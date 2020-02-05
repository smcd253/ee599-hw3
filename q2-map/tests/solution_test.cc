#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
/**************** add() overload1 ****************/
TEST(ADD_OVERLOAD1_INT_TEST, STANDARD) {
  Solution solution;
  int a = 1;
  int b = 2;
  int actual = solution.add(a, b);
  int expected = 3;
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD1_INT_TEST, ZEROS) {
  Solution solution;
  int a = 0;
  int b = 0;
  int actual = solution.add(a, b);
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD1_INT_TEST, POS_TO_NEG_OVERFLOW) {
  Solution solution;
  int a = INT32_MAX;
  int b = 10;
  int actual = solution.add(a, b);
  int expected = INT32_MAX;
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD1_INT_TEST, NEG_TO_POS_OVERFLOW) {
  Solution solution;
  int a = INT32_MIN;
  int b = -10;
  int actual = solution.add(a, b);
  int expected = INT32_MIN;
  EXPECT_EQ(expected, actual);
}

/**************** add() overload2 ****************/
TEST(ADD_OVERLOAD2_STRINGS_TEST, STANDARD) {
  Solution solution;
  std::string a = "a";
  std::string b = "b";
  std::string actual = solution.add(a, b);
  std::string expected = "ab";
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD2_STRINGS_TEST, EMPTY_1) {
  Solution solution;
  std::string a = "";
  std::string b = "b";
  std::string actual = solution.add(a, b);
  std::string expected = "b";
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD2_STRINGS_TEST, EMPTY_2) {
  Solution solution;
  std::string a = "a";
  std::string b = "";
  std::string actual = solution.add(a, b);
  std::string expected = "a";
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD2_STRINGS_TEST, EMPTY_BOTH) {
  Solution solution;
  std::string a = "";
  std::string b = "";
  std::string actual = solution.add(a, b);
  std::string expected = "";
  EXPECT_EQ(expected, actual);
}

// TEST(ADD_OVERLOAD2_STRINGS_TEST, STRING_TOO_LARGE) {
//   Solution solution;
//   std::string a;
//   for (int i = 0; i < a.max_size(); i++)
//   {
//     a.append("a");
//   }
//   std::string b = "b";
//   std::string actual = solution.add(a, b);
//   std::string expected = "invalid: input string(s) too large!";
//   EXPECT_EQ(expected, actual);
// }

/**************** add() overload3 ****************/
TEST(ADD_OVERLOAD3_STRING_INT_TEST, STANDARD) {
  Solution solution;
  std::string a = "a";
  int b = 1;
  std::string actual = solution.add(a, b);
  std::string expected = "a1";
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD3_STRING_INT_TEST, EMPTY_STRING) {
  Solution solution;
  std::string a = "";
  int b = 1;
  std::string actual = solution.add(a, b);
  std::string expected = "1";
  EXPECT_EQ(expected, actual);
}

// TEST(ADD_OVERLOAD3_STRING_INT_TEST, STRING_TOO_LARGE) {
//   Solution solution;
//   std::string a;
//   for (int i = 0; i < a.max_size(); i++)
//   {
//     a.append("a");
//   }
//   int b = 1;
//   std::string actual = solution.add(a, b);
//   std::string expected = "invalid: input string(s) too large!";
//   EXPECT_EQ(expected, actual);
// }

/**************** add() overload4 ****************/
TEST(ADD_OVERLOAD4_INT_STRING_TEST, STANDARD) {
  Solution solution;
  int a = 1;
  std::string b = "b";
  std::string actual = solution.add(a, b);
  std::string expected = "1b";
  EXPECT_EQ(expected, actual);
}

TEST(ADD_OVERLOAD4_INT_STRING_TEST, EMPTY_STRING) {
  Solution solution;
  int a = 1;
  std::string b = "";
  std::string actual = solution.add(a, b);
  std::string expected = "1";
  EXPECT_EQ(expected, actual);
}

// TEST(ADD_OVERLOAD4_INT_STRING_TEST, STRING_TOO_LARGE) {
//   Solution solution;
//   int a = 1;
//   std::string b;
//   for (int i = 0; i < b.max_size(); i++)
//   {
//     b.append("b");
//   }
//   std::string actual = solution.add(a, b);
//   std::string expected = "invalid: input string(s) too large!";
//   EXPECT_EQ(expected, actual);
// }