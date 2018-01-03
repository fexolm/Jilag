#include <iostream>
#include "nsa.hpp"
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

  nsa.determine();
  return 0;
}