//
// Created by fexolm on 28.01.18.
//

#include <boost/test/unit_test.hpp>
#include <Regex.hpp>

BOOST_AUTO_TEST_SUITE(re_test3)

BOOST_AUTO_TEST_CASE(test3) {
  Regex regex("abc*");
  BOOST_CHECK(regex.is_match("abc"));
  BOOST_CHECK(regex.is_match("abcccccc"));
  BOOST_CHECK(regex.is_match("ab"));
  BOOST_CHECK(!regex.is_match("abccccccce"));
}

BOOST_AUTO_TEST_SUITE_END()
