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

TEST(ACADEMIC_RECORD_TEST, CONSTRUCTOR_COPY) 
{
  const AcademicRecord src(1, 2, 3);
  AcademicRecord test(src);
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {1, 2, 3};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, CONSTRUCTOR_ASSIGNMENT) 
{
  const AcademicRecord src(1, 2, 3);
  AcademicRecord test = src;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {1, 2, 3};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, PP_OPERATOR) 
{
  AcademicRecord test(1, 2, 3);
  ++test;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {11, 12, 13};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, OPERATOR_PP) 
{
  AcademicRecord test(1, 2, 3);
  test++;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {11, 12, 13};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, MM_OPERATOR) 
{
  AcademicRecord test(21, 22, 23);
  --test;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {1, 2, 3};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, OPERATOR_MM) 
{
  AcademicRecord test(21, 22, 23);
  test--;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {1, 2, 3};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, OPERATOR_PE) 
{
  AcademicRecord test(1, 2, 3);
  test += 10;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {11, 12, 13};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, OPERATOR_ME) 
{
  AcademicRecord test(21, 22, 23);
  test -= 10;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {11, 12, 13};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, OPERATOR_EE_TRUE) 
{
  AcademicRecord LHS(21, 22, 23);
  AcademicRecord RHS(21, 22, 23);  
  bool actual = (LHS == RHS);
  bool expected = true;
  EXPECT_EQ(actual, expected);
}

TEST(ACADEMIC_RECORD_TEST, OPERATOR_EE_FALSE) 
{
  AcademicRecord LHS(1, 2, 3);
  AcademicRecord RHS(21, 22, 23);  
  bool actual = (LHS == RHS);
  bool expected = false;
  EXPECT_EQ(actual, expected);
}


TEST(ACADEMIC_RECORD_TEST, OUT_OF_BOUNDS_HIGH) 
{
  AcademicRecord test(91, 89, 92);
  test++;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {100, 99, 100};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, OUT_OF_BOUNDS_LOW) 
{
  AcademicRecord test(21, 2, 3);
  test--;
  int actual[3] = {test.math, test.computers, test.physics};
  int expected[3] = {1, 0, 0};
  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(actual[i], expected[i]);
  }
}

TEST(ACADEMIC_RECORD_TEST, PRINT)
{
  AcademicRecord test(90, 95, 97);
  std::string expected = "Math::90\nComputers::95\nPhysics::97\n";
  std::string actual = test.print();
  EXPECT_EQ(actual, expected);
}