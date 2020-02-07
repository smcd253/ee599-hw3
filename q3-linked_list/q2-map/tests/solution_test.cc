#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(FIT_SUM_TEST, PROVIDED_TEST_CASE1) {
  Solution solution;
  std::vector<int> input = {3, 7, 11, 15};
  int sum = 10;
  std::vector<int> actual = solution.fit_sum(input, sum);
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(expected, actual);
}

TEST(FIT_SUM_TEST, PROVIDED_TEST_CASE2) {
  Solution solution;
  std::vector<int> input = {3, 7, 11, 15};
  int sum = 180;
  std::vector<int> actual = solution.fit_sum(input, sum);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(FIT_SUM_TEST, PROVIDED_TEST_CASE3) {
  Solution solution;
  std::vector<int> input = {1, 4, 3, 2};
  int sum = 5;
  std::vector<int> actual = solution.fit_sum(input, sum);
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(expected, actual);
}

TEST(FIT_SUM_TEST, EMPTY) {
  Solution solution;
  std::vector<int> input = {};
  int sum = 180;
  std::vector<int> actual = solution.fit_sum(input, sum);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(FIT_SUM_TEST, NEGATIVES) {
  Solution solution;
  std::vector<int> input = {-1, -2, -3, -4, -5};
  int sum = -9;
  std::vector<int> actual = solution.fit_sum(input, sum);
  std::vector<int> expected = {4, 3};
  EXPECT_EQ(expected, actual);
}
