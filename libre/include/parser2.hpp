//
// Created by fexolm on 19.01.18.
//

#pragma once
#include <iostream>
#include <memory>
#include "lex_cases.hpp"
#include "lex_constants.hpp"
#include "nsa.hpp"
#include "dsa.hpp"

/*!
 * @brief regular expression parser
 *
 * based on grammatic:
 *
 * stmt -> expr mult stmt | e
 * expr -> term | ( complex_expr )
 * mult -> * | { range } | e
 * range -> _num , _num
 * _num -> num | e
 * complex_expr -> stmt expr_union
 * union -> '|' stmt union
 */

class Parser2 {
public:
  jilag::DSA parse(std::istream &in, void *data = nullptr);
private:
  void stmt(std::istream &in, jilag::NSA &);
  void expr(std::istream &in, jilag::NSA &);
  void mult(std::istream &in, jilag::NSA &);
  void range(std::istream &in, jilag::NSA &);
  void complex_expr(std::istream &istream, jilag::NSA &a);
  void expr_union(std::istream &in, jilag::NSA &);
  void term(std::istream &in, jilag::NSA &);
  void num_(std::istream &in, jilag::NSA &);
};