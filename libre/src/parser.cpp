//
// Created by fexolm on 14.01.18.
//

#include <vector>
#include "parser.hpp"
jilag::DSA Parser::parse(std::istream &in) {
  jilag::NSA nsa;
  expr(in, nsa);
  nsa.remove_epsilons();
  auto dsa = jilag::DSA::build_from_nsa(nsa);

  auto table = nsa.make_translation_table_();
  return dsa;
}
void Parser::expr(std::istream &in, jilag::NSA &nsa) {
  int c = in.peek();
  switch (c) {
  __dot__case__ dot(in, nsa);
    break;
  __symbol__case__ symbol(in, nsa);
    break;
  __escape__case__ escape(in, nsa);
    break;
  __open__paren__case__ add_nsa(in, nsa);
    break;
  __pipe__case__ add_union(in, nsa);
    break;
  default: return; // eof
  }
  expr(in, nsa);
}
void Parser::dot(std::istream &in, jilag::NSA &) {

}
void Parser::symbol(std::istream &in, jilag::NSA &nsa) {
  nsa.push_back(in.get());
}
void Parser::escape(std::istream &in, jilag::NSA &) {

}
void Parser::add_nsa(std::istream &in, jilag::NSA &nsa) {
  in.get();
  jilag::NSA nsa2;
  expr(in, nsa2);
  in.get(); // close paren
  make_closure(in, nsa2);
  nsa.push_back(std::move(nsa2));
}
void Parser::add_union(std::istream &in, jilag::NSA &nsa) {
  in.get();
  jilag::NSA nsa2;
  expr(in, nsa2);
  nsa.alternative_branch(std::move(nsa2));
}
void Parser::make_closure(std::istream &in, jilag::NSA &nsa) {
  if (in.peek()!=STAR)
    return;
  switch (in.get()) {
  case (STAR): nsa.make_kleene_closure();
    break;
  default:break;
  }
}
