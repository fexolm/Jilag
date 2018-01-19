//
// Created by fexolm on 14.01.18.
//
#include <string>
#include <sstream>
#include "parser2.hpp"

bool check_string(jilag::DSA &dsa, const std::string &str) {
  dsa.reset();
  bool correct = true;
  for (int i = 0; correct && i < str.length(); i++) {
    correct = dsa.move(str[i]);
  }
  return correct && dsa.final();
}

int main() {
  std::string s = "abc(kek|lel)*";
  std::stringstream ss;
  ss << s;
  Parser2 p;
  auto dsa = p.parse(ss);

  std::cout << check_string(dsa, "abc");

  std::cout << check_string(dsa, "abckek");

  std::cout << check_string(dsa, "abclel");


  std::cout << check_string(dsa, "abck");


  std::cout << check_string(dsa, "abckekkeklel");
}