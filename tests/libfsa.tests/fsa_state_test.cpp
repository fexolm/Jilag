#include <boost/test/unit_test.hpp>
#include "parser2.hpp"

bool check_string(jilag::DSA &dsa, const std::string &str) {
  dsa.reset();
  bool correct = true;
  for (uint i = 0; correct && i < str.length(); i++) {
    correct = dsa.move(str[i]);
  }
  BOOST_CHECK(std::string((char *) dsa.data())=="kek");
  return correct && dsa.final();
}

BOOST_AUTO_TEST_SUITE(re_test1)

BOOST_AUTO_TEST_CASE (test1) {
  std::string s = "abc(kek|lel)*";
  std::stringstream ss;
  ss << s;
  Parser2 p;
  auto dsa = p.parse(ss, (void *) "kek");

  BOOST_CHECK(check_string(dsa, "abc"));

  BOOST_CHECK(check_string(dsa, "abckek"));

  BOOST_CHECK(check_string(dsa, "abclel"));

  BOOST_CHECK(!check_string(dsa, "abck"));

  BOOST_CHECK(!check_string(dsa, "abckekeklel"));
}

BOOST_AUTO_TEST_SUITE_END()