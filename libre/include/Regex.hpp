//
// Created by fexolm on 24.02.18.
//

#pragma once
#include <string>
#include <sstream>
#include <memory>
#include <dsa.hpp>
#include <nsa.hpp>
#include "parser2.hpp"

class Regex {
private:
  std::unique_ptr<jilag::DSA> dsa_;
public:
  Regex(const std::string &pattern) {
    std::stringstream ss;
    ss << pattern;
    Parser2 p;
    dsa_ = std::make_unique<jilag::DSA>(p.parse(ss));
  }

  bool is_match(const std::string &str) {
    dsa_->reset();
    bool correct = true;
    for (uint i = 0; correct && i < str.length(); i++) {
      correct = dsa_->move(str[i]);
    }
    return correct && dsa_->final();
  }
};
