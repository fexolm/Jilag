//
// Created by fexolm on 07.01.18.
//
#pragma once

#include <unordered_set>
#include <unordered_map>
#include "state_transition_table.hpp"
#include "nsa.hpp"
namespace jilag {
namespace __internal {

class __DSA_State {
private:
  bool final_;
  mutable bool cache_valid_;
  mutable std::unordered_set<int> symbol_cache_;
  void *data_;
  std::unordered_map<int, __DSA_State *> symbol_map_;
public:
  __DSA_State();
  bool &final();
  __DSA_State *from_symbol(int s);
  const std::unordered_set<int> &symbols() const;
  void add_symbol(int s, __DSA_State *state);
  void *data();
  void set_data(void *data);
};
}

class DSA {
  typedef __internal::__DSA_State state_t;
private:
  std::vector<state_t *> states_;
  state_t *first_;
  state_t *current_;
  DSA();
  std::vector<state_t *> copy_states(const DSA &) const;
  void dfs_copy(std::map<intptr_t, state_t *> &used, state_t *start) const;
public:
  DSA(const DSA &);
  DSA &operator=(const DSA &);
  DSA(DSA &&) = default;
  DSA &operator=(DSA &&) = default;
  virtual ~DSA();
  static DSA build_from_nsa(const NSA &);

  bool move(symbol_t);

  bool final() const;

  void reset();
  void *data();

};
}