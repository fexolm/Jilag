//
// Created by fexolm on 07.01.18.
//
#pragma once

#include "state_transition_table.hpp"
#include "nsa.hpp"
namespace jilag {
class DSA {
private:
  __internal::__state_translation_table translation_table_;
  int current_;
  DSA();
public:
  static DSA build_from_nsa(const NSA &);

  bool move(symbol_t);

  bool final() const;

  void reset();
};
}