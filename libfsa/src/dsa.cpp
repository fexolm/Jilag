//
// Created by fexolm on 07.01.18.
//

#include "dsa.hpp"
#include <algorithm>

namespace jilag {

namespace __internal {

bool &__internal::__DSA_State::final() {
  return final_;
}

__DSA_State *__DSA_State::from_symbol(int s) {
  if (!symbol_map_.count(s)) {
    return nullptr;
  }
  return symbol_map_[s];
}

const std::unordered_set<int> &__DSA_State::symbols() const {
  if (!cache_valid_) {
    cache_valid_ = true;
    symbol_cache_.clear();
    for (auto &p : symbol_map_) {
      symbol_cache_.insert(p.first);
    }
  }
  return symbol_cache_;
}

void __DSA_State::add_symbol(int s, __DSA_State *state) {
  cache_valid_ = false;
  symbol_map_[s] = state;
}

__DSA_State::__DSA_State()
    : final_(false), cache_valid_(false) {}

} // namespace __internal

DSA::DSA() : current_(0) {}

DSA::DSA(const DSA &rhs) {
  states_ = copy_states(rhs);
  first_ = states_[0];
  current_ = states_[0];
}

DSA &DSA::operator=(const DSA &rhs) {
  states_ = copy_states(rhs);
  first_ = states_[0];
  current_ = states_[0];
  return *this;
}

DSA DSA::build_from_nsa(const NSA &nsa) {
  auto table = nsa.make_translation_table_();

  std::vector<state_t *> states(table.states.size());

  for (int i = 0; i < states.size(); ++i) {
    states[i] = new state_t;
  }
  for (int i = 0; i < table.states.size(); ++i) {
    for (auto p : table.states[i]) {
      states[i]->add_symbol(p.first, states[p.second]);
    }
  }
  for (auto f : table.finals) {
    states[f]->final() = true;
  }

  DSA result;
  result.first_ = states[0];
  result.states_ = std::move(states);
  result.reset();
  return result;
}
bool DSA::move(symbol_t symbol) {
  auto next = current_->from_symbol(symbol);
  if (!next) {
    return false;
  }
  current_ = next;
  return true;
}
bool DSA::final() const {
  return current_->final();
}
void DSA::reset() {
  current_ = first_;
}
DSA::~DSA() {
  for (auto &s : states_) {
    delete s;
  }
}
std::vector<DSA::state_t *> DSA::copy_states(const DSA &rhs) const {
  std::map<intptr_t, DSA::state_t *> used;
  dfs_copy(used, rhs.first_);
  std::vector<DSA::state_t *> result;
  std::transform(used.begin(), used.end(), std::back_inserter(result), [](auto kv) {
    return kv.second;
  });
  return result;
}
void DSA::dfs_copy(std::map<intptr_t, state_t *> &used, DSA::state_t *start) const {
  intptr_t ind = reinterpret_cast<intptr_t >(start);
  if (used.count(ind))
    return;
  auto state = new DSA::state_t;
  state->final() = start->final();
  used[ind] = state;

  for (auto sy : start->symbols()) {
    auto to = start->from_symbol(sy);
    dfs_copy(used, to);
    state->add_symbol(sy, used[reinterpret_cast<intptr_t >(to)]);
  }
}
} // namespace jilag
