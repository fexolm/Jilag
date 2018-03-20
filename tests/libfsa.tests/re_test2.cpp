//
// Created by fexolm on 28.01.18.
//

#include <boost/test/unit_test.hpp>
#include "parser2.hpp"

bool check_string(jilag::DSA &dsa, const std::string &str) {
  dsa.reset();
  bool correct = true;
  for (uint i = 0; correct && i < str.length(); i++) {
    correct = dsa.move(str[i]);
  }
  return correct && dsa.final();
}

BOOST_AUTO_TEST_SUITE(re_test2)

BOOST_AUTO_TEST_CASE(test2) {
  std::string s = "(0|1|2|3|4|5|6|7|8|9)*(a|b|c)(a|b|c)*";
  std::stringstream ss;
  ss << s;
  Parser2 p;
  auto dsa = p.parse(ss);

  BOOST_CHECK(check_string(dsa, "012343212aabbccacba"));
  BOOST_CHECK(check_string(dsa, "343212acacba"));
  BOOST_CHECK(check_string(dsa, "aabbccacba"));
  BOOST_CHECK(!check_string(dsa, "aabbc123cacba"));

  auto dsa2(dsa);
  BOOST_CHECK(check_string(dsa2, "012343212aabbccacba"));
  BOOST_CHECK(check_string(dsa2, "343212acacba"));
  BOOST_CHECK(check_string(dsa2, "aabbccacba"));
  BOOST_CHECK(!check_string(dsa2, "aabbc123cacba"));
}

BOOST_AUTO_TEST_SUITE_END()
