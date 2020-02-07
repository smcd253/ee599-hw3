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
