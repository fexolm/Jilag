//
// Created by fexolm on 14.01.18.
//

#pragma once
#include <iostream>
#include <memory>
#include "lex_cases.hpp"
#include "lex_constants.hpp"
#include "nsa.hpp"
#include "dsa.hpp"

class Parser {
public:
  jilag::DSA parse(std::istream &in);
private:
  void expr(std::istream &in, jilag::NSA &);
  void dot(std::istream &in, jilag::NSA &);
  void symbol(std::istream &in, jilag::NSA &);
  void escape(std::istream &in, jilag::NSA &);

  void add_nsa(std::istream &istream, jilag::NSA &a);
  void add_union(std::istream &in, jilag::NSA &);
  void make_closure(std::istream &in, jilag::NSA &);
};