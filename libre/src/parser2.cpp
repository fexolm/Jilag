//
// Created by fexolm on 19.01.18.
//

#include "parser2.hpp"
jilag::DSA Parser2::parse(std::istream &in, void *data) {
  jilag::NSA nsa;
  stmt(in, nsa);
  nsa.change_data(data);
  nsa.change_priority(0);
  nsa.remove_epsilons();
  auto table = nsa.make_translation_table_();
  auto dsa = jilag::DSA::build_from_nsa(nsa);
  return dsa;
}
void Parser2::stmt(std::istream &in, jilag::NSA &nsa) {
  auto c = in.peek();
  if (c==in.eof() || c==-1 || c==PIPE || c==CLOSE_PAREN)
    return;
  jilag::NSA nsa2;
  expr(in, nsa2);
  mult(in, nsa2);
  stmt(in, nsa2);
  nsa.push_back(std::move(nsa2));
}
void Parser2::expr(std::istream &in, jilag::NSA &nsa) {
  int c = in.peek();
  switch (c) {
  __term__case__ term(in, nsa);
    break;
  __open__paren__case__ in.get();
    complex_expr(in, nsa);
    if (in.get()!=CLOSE_PAREN)
      throw;
    break;
  default: throw;
  }
}
void Parser2::mult(std::istream &in, jilag::NSA &nsa) {
  switch (in.peek()) {
  case STAR:nsa.make_kleene_closure();
    in.get();
    break;
  case PLUS:
    //TODO: copy nsa and make kleenee_closure
    throw;
    break;
  case OPEN_RANGE_BRACKET:
    //TODO: range
    throw;
    break;
  default: break;
  }
}
void Parser2::range(std::istream &in, jilag::NSA &) {
  throw;
}
void Parser2::complex_expr(std::istream &in, jilag::NSA &nsa) {
  jilag::NSA nsa2;
  stmt(in, nsa2);
  expr_union(in, nsa2);
  nsa.push_back(std::move(nsa2));
}
void Parser2::expr_union(std::istream &in, jilag::NSA &nsa) {
  while (in.peek()==PIPE) {
    in.get();
    jilag::NSA nsa2;
    stmt(in, nsa2);
    nsa.alternative_branch(std::move(nsa2));
  }
}
void Parser2::term(std::istream &in, jilag::NSA &nsa) {
  nsa.push_back(in.peek());
  in.get();
}
void Parser2::num_(std::istream &in, jilag::NSA &) {
  throw;
}
