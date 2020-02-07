#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(VALID_BRACKETS_TEST, EMPTY) {
  Solution solution;
  std::string input = "";
  bool expected = false;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, BRACKETS_ONLY_SINGULAR) {
  Solution solution;
  std::string input = "{}";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, BRACKETS_ONLY_PLURAL_CONCENTRIC) {
  Solution solution;
  std::string input = "[{()}]";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, BRACKETS_ONLY_PLURAL_CONSECUTIVE) {
  Solution solution;
  std::string input = "{}()[]";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, BRACKETS_SEPARATED) {
  Solution solution;
  std::string input = "{} (a, b) [ LIFE IS A GIFT!]";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, NO_CONTAINMENT_LEADING) {
  Solution solution;
  std::string input = " {}";
  bool expected = false;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, NO_CONTAINMENT_TRAILING) {
  Solution solution;
  std::string input = "{} ";
  bool expected = false;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, PROVIDED_TEST_CASE1) {
  Solution solution;
  std::string input = "(a+b)";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, PROVIDED_TEST_CASE2) {
  Solution solution;
  std::string input = "(a+b)[c*d]{5g+h}";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, PROVIDED_TEST_CASE3) {
  Solution solution;
  std::string input = "(a+b]";
  bool expected = false;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, PROVIDED_TEST_CASE4) {
  Solution solution;
  std::string input = "(7h+[5c)+7]";
  bool expected = false;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, PROVIDED_TEST_CASE5) {
  Solution solution;
  std::string input = "{2k+[5j]}";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}

TEST(VALID_BRACKETS_TEST, PROVIDED_TEST_CASE6) {
  Solution solution;
  std::string input = "{2k++[5--*j]}";
  bool expected = true;
  bool actual = solution.valid_brackets(input);
  EXPECT_EQ(expected, actual);
}
