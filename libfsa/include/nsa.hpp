//
// Created by fexolm on 02.01.18.
//

#pragma once
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include "state_transition_table.hpp"

namespace jilag {

typedef int symbol_t;
const symbol_t epsilon = -1;

namespace __internal {

class __NSA_State {
public:
  typedef __NSA_State *ptr_t;
  typedef const ptr_t const_ptr_t;
  typedef std::unordered_set<ptr_t> set_t;
  typedef std::unordered_map<symbol_t, set_t> map_t;
private:
  map_t symbol_map_;
  bool final_;
  mutable bool chache_changed_;
  mutable std::set<symbol_t> possible_symbols_chache_;
	void *state_data_;
public:
	int priority;
  __NSA_State();
  __NSA_State &add(symbol_t, const_ptr_t);
  const set_t &get(symbol_t);
  void make_final() noexcept;
  bool final() const noexcept;
  void remove_epsilons();
  const std::set<symbol_t> &possible_symbols() const noexcept;
  const std::set<__NSA_State *> conneted_with() const noexcept;
	void *state_data() noexcept;
	void set_data(void *data) noexcept;
};
} // namespace __internal
class NSA {
private:
  typedef __internal::__NSA_State state_t;
  std::vector<state_t *> states_;
  state_t *begin_;
  state_t *end_; //end is always final state
  state_t *current_;
  bool free_pointers_;
  bool allow_change_;
  void remove_unreachable();

public:
  NSA();
  NSA(const NSA &) = delete;
  NSA &operator=(const NSA &) = delete;
  NSA(NSA &&);
  NSA &operator=(NSA &&);
  virtual ~NSA();
	
  NSA &push_back(symbol_t symbol);

  NSA &push_back(NSA &&);

  NSA &add_union(std::vector<NSA> &v);

  NSA &make_kleene_closure();

  NSA &remove_epsilons();

  NSA &alternative_branch(NSA &&);

	NSA &change_priority(int priority) noexcept;
	NSA &change_data(void *data) noexcept;
  __internal::__state_translation_table
  __attribute__((visibility("hidden"))) make_translation_table_() const;
};

} // namespace jilag
