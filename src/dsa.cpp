//
// Created by fexolm on 07.01.18.
//

#include "dsa.hpp"

namespace jilag {
DSA::DSA() : current_(0) {}

DSA DSA::build_from_nsa(const NSA &nsa) {
  DSA result;
  result.translation_table_ = nsa.make_translation_table_();
  return result;
}
bool DSA::move(symbol_t symbol) {
  auto &state = translation_table_.states[current_];
  if (!state.count(symbol)) {
    return false;
  }
  current_ = state[symbol];
}
bool DSA::final() const {
  return static_cast<bool>(translation_table_.finals.count(current_));
}
void DSA::reset() {
  current_ = 0;
}

}