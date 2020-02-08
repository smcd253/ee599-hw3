#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(ACADEMIC_RECORD_TEST, CONSTRUCTOR_DEFAULT) 
{
  AcademicRecord test;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {0, 0, 0};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, CONSTRUCTOR_PARAMETRIZED) 
{
  AcademicRecord test(1, 2, 3);
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {1, 2, 3};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}