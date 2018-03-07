//
// Created by fexolm on 02.01.18.
//
#include <numeric>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
#include "nsa.hpp"
#include "index_tree.hpp"

namespace jilag {
namespace __internal {
__NSA_State::__NSA_State() : chache_changed_(true), state_data_(nullptr) {}

__NSA_State &__NSA_State::add(symbol_t symbol, const_ptr_t state) {
  chache_changed_ = true;
  symbol_map_[symbol].insert(state);
  return *this;
}

const __NSA_State::set_t &__NSA_State::get(symbol_t symbol) {
  return symbol_map_[symbol];
}

void __NSA_State::remove_epsilons() {
  chache_changed_ = true;
  if (symbol_map_.count(epsilon)) {
    set_t visited = symbol_map_[epsilon];
    symbol_map_.erase(epsilon);
    std::stack<ptr_t> to_visit;
    for (auto &state : visited) {
      to_visit.push(state);
    }
    while (!to_visit.empty()) {
      auto state = to_visit.top();
      if (state->final_) {
        final_ = true;
      }
      to_visit.pop();
      for (auto &p : state->symbol_map_) {
        if (p.first==epsilon) {
          for (auto &s : p.second) {
            if (!visited.count(s)) {
              to_visit.push(s);
              visited.insert(s);
            }
          }
        } else {
          symbol_map_[p.first].insert(p.second.begin(), p.second.end());
        }
      }
    }
  }
}

void __NSA_State::make_final() noexcept{
  final_ = true;
}

bool __NSA_State::final() const noexcept{
  return final_;
}

const void *__NSA_State::state_data() noexcept{
	return state_data_;
}

void __NSA_State::set_data(void *data) noexcept {
	state_data_ = data;
}

const std::set<symbol_t> &__NSA_State::possible_symbols() const noexcept{
  if (chache_changed_) {
    chache_changed_ = false;
    possible_symbols_chache_.clear();
    for (auto &p : symbol_map_) {
      possible_symbols_chache_.insert(p.first);
    }
  }
  return possible_symbols_chache_;
}

const std::set<__NSA_State *> __NSA_State::conneted_with() const noexcept{
  std::set<__NSA_State *> result;
  for (auto s : symbol_map_) {
    result.insert(s.second.begin(), s.second.end());
  }
  return result;
}

} // namespace __internal

NSA::NSA() :
    begin_(new state_t),
    end_(new state_t),
    current_(begin_),
    free_pointers_(true),
    allow_change_(true) {
  states_.push_back(begin_);
  states_.push_back(end_);
  begin_->add(epsilon, end_);
}

NSA::NSA(NSA &&rhs) :
    begin_(rhs.begin_),
    end_(rhs.end_),
    states_(std::move(rhs.states_)),
    allow_change_(rhs.allow_change_) {
  rhs.free_pointers_ = false;
}

NSA &NSA::operator=(NSA &&rhs) {
  begin_ = rhs.begin_;
  end_ = rhs.end_;
  states_ = std::move(rhs.states_);
  allow_change_ = rhs.allow_change_;
  rhs.free_pointers_ = false;
  return *this;
}

NSA::~NSA() {
  if (free_pointers_) {
    for (auto &s: states_) {
      delete s;
    }
  }
}

NSA &NSA::push_back(symbol_t symbol) {
  if (!allow_change_)
    throw;
  auto state = new state_t;
  states_.push_back(state);
  end_->add(symbol, state);
  end_ = state;
  return *this;
}

NSA &NSA::push_back(NSA &&rhs) {
  if (!allow_change_)
    throw;
  rhs.free_pointers_ = false;
  states_.insert(states_.end(), rhs.states_.begin(), rhs.states_.end());
  end_->add(epsilon, rhs.begin_);
  end_ = rhs.end_;
  return *this;
}

NSA &NSA::add_union(std::vector<NSA> &v) {
  if (!allow_change_)
    throw;
  auto end_state = new state_t;
  uint size = std::accumulate(v.begin(), v.end(), 0u, [](uint old, NSA &nsa) {
    return old + nsa.states_.size();
  });
  states_.reserve(size);
  for (std::vector<NSA>::iterator iter = v.begin(); iter!=v.end(); ++iter) {
    auto nsa(std::move(*iter));
    nsa.free_pointers_ = false;
    states_.insert(states_.end(), nsa.states_.begin(), nsa.states_.end());
    nsa.end_->add(epsilon, end_state);
    end_->add(epsilon, iter->begin_);
  }
  end_ = end_state;
  return *this;
}

NSA &NSA::make_kleene_closure() {
  if (!allow_change_)
    throw;
  auto nbegin = new state_t;
  auto nend = new state_t;
  end_->add(epsilon, nend);
  end_->add(epsilon, begin_);
  nbegin->add(epsilon, begin_);
  nbegin->add(epsilon, nend);
  begin_ = nbegin;
  end_ = nend;
  states_.push_back(nend);
  states_.push_back(nbegin);
  return *this;
}

NSA &NSA::remove_epsilons() {
  if (!allow_change_)
    throw;
  end_->make_final();
  allow_change_ = false;
  for (auto &s : states_) {
    s->remove_epsilons();
  }
  remove_unreachable();
  return *this;
}

__internal::__state_translation_table NSA::make_translation_table_() const {
  int current = 0;
  __internal::__IndexTree used;
  std::vector<std::vector<state_t *>> states;
  std::vector<std::map<symbol_t, int>> ksa_table;
	std::vector<std::pair<int, const void *>> states_data;
  states.push_back({begin_});
	states_data.push_back({begin_->priority, begin_->state_data()});
  used.get_index({begin_}); //x0
  ksa_table.push_back(std::map<symbol_t, int>());
  std::set<int> finals;
  while (current!=states.size()) {
    // all symbols containing in current state set
    std::unordered_set<symbol_t> symbols;
    for (auto &state : states[current]) {
      auto &possible = state->possible_symbols();
      symbols.insert(possible.begin(), possible.end());
    }
    // get sets of states reachable from current state set by each symbol
    // if there are new sets of states, push them to states vector
    // new state is final if it contains at least one final state
    for (auto symbol : symbols) {
      std::set<__internal::__NSA_State::ptr_t> nstate;
      bool final = false;
      for (auto state : states[current]) {
        if (state->possible_symbols().count(symbol)) {
          auto can_move_to = state->get(symbol);
          nstate.insert(can_move_to.begin(), can_move_to.end());
          final = final ||
              std::find_if(nstate.begin(), nstate.end(), [](auto st) {
                return st->final();
              })!=nstate.end();
        }
      }
      std::vector<__internal::__NSA_State::ptr_t> nstate_v(nstate.begin(), nstate.end());
			
			
      int index = used.get_index(nstate_v);
      if (index==states.size()) {
        if (final) {
          finals.insert(index);
        }
        states.push_back(nstate_v);
        ksa_table.push_back(std::map<symbol_t, int>());
				states_data.push_back({99999, nullptr});
      }

			auto best = std::min_element(nstate_v.begin(),nstate_v.end(),
				 	[](auto lhs, auto rhs) {
						return lhs->priority < rhs->priority;
			});

			states_data[index] = std::min(states_data[index], 
					{(*best)->priority, (*best)->state_data()});

      ksa_table[current][symbol] = index;
    }
    current++;
  }
  __internal::__state_translation_table result;
  result.states = std::move(ksa_table);
  result.finals = std::move(finals);
  return result;
}

void NSA::remove_unreachable() {
  std::unordered_set<state_t *> visited;
  std::stack<state_t *> to_visit;
  to_visit.push(begin_);
  visited.insert(begin_);
  while (!to_visit.empty()) {
    auto state = to_visit.top();
    to_visit.pop();
    for (auto s : state->conneted_with()) {
      if (!visited.count(s)) {
        visited.insert(s);
        to_visit.push(s);
      }
    }
  }
  states_.erase(std::remove_if(states_.begin(), states_.end(), [&visited](auto &state) {
    if (visited.count(state)==0) {
      delete state;
      return true;
    }
    return false;
  }), states_.end());
}
NSA &NSA::alternative_branch(NSA &&nsa) {
  nsa.free_pointers_ = false;
  states_.insert(states_.end(), nsa.states_.begin(), nsa.states_.end());
  begin_->add(epsilon, nsa.begin_);
  nsa.end_->add(epsilon, end_);
  return *this;
}

NSA &NSA::change_priority(int priority) noexcept {
	for(auto s : states_) {
		s->priority = priority;
	}
	return *this;
}

NSA &NSA::change_data(void *data) noexcept {
	for(auto s : states_) {
		s->set_data(data);
	}
	return *this;
}
} // namespace jilag
