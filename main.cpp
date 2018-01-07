#include <iostream>
#include "nsa.hpp"
#include "dsa.hpp"
#include <string>

bool check_string(jilag::DSA &dsa, const std::string &str) {
  dsa.reset();
  bool correct = true;
  for (int i = 0; correct && i < str.length(); i++) {
    correct = dsa.move(str[i]);
  }
  return correct && dsa.final();
}

int main() {
  jilag::NSA nsa;

  nsa.push_back(int('a'));
  nsa.push_back(int('b'));

  jilag::NSA cd;
  cd.push_back(int('c'));
  cd.push_back(int('d'));
  cd.make_kleene_closure();

  jilag::NSA ek;
  ek.push_back('e');
  ek.push_back('k');

  std::vector<jilag::NSA> v;
  v.push_back(std::move(cd));
  v.push_back(std::move(ek));

  jilag::NSA cdek;
  cdek.add_union(v);
  cdek.make_kleene_closure();

  jilag::NSA rcd;
  rcd.push_back(int('r'));
  rcd.push_back(int('c'));
  rcd.push_back(int('d'));

  std::vector<jilag::NSA> v2;
  v2.push_back(std::move(cdek));
  v2.push_back(std::move(rcd));

  jilag::NSA cdekrcd;
  cdekrcd.add_union(v2);

  nsa.push_back(std::move(cdekrcd));

  nsa.remove_epsilons();

  jilag::DSA dsa = jilag::DSA::build_from_nsa(nsa);

  std::cout << check_string(dsa, "ab") << std::endl;

  std::cout << check_string(dsa, "abrcd") << std::endl;

  std::cout << check_string(dsa, "abek") << std::endl;

  std::cout << check_string(dsa, "abcd") << std::endl;

  std::cout << check_string(dsa, "abcdekcd") << std::endl;

  std::cout << check_string(dsa, "abrcdcd") << std::endl;

  return 0;
}