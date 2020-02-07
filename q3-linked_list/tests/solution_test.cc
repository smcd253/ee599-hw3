#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
#include <utility>
#include <iostream> // for debugging

TEST(SINGLY_LINKED_LIST_TEST, DEFAULT_CONSTRUCTOR_STATIC)
{
  SinglyLinkedList sll;
  std::pair<ListNode*, int> expected(nullptr, 0);
  std::pair<ListNode*, int> actual(sll.head_, sll.size());
  expected.first = nullptr;
  expected.second = 0;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, DEFAULT_CONSTRUCTOR_DYNAMIC)
{
  SinglyLinkedList* sll = new SinglyLinkedList();
  std::pair<ListNode*, int> expected(nullptr, 0);
  std::pair<ListNode*, int> actual(sll->head_, sll->size());
  expected.first = nullptr;
  expected.second = 0;
  EXPECT_EQ(expected, actual);
  delete sll;
}

// TEST(SINGLY_LINKED_LIST_TEST, DESTRUCTOR)
// {
//     SinglyLinkedList* sll = new SinglyLinkedList();
//     delete sll;

//     SinglyLinkedList* expected = nullptr;

//     EXPECT_EQ(expected, sll);
// }

TEST(SINGLY_LINKED_LIST_TEST, EMPTY_TRUE)
{
  SinglyLinkedList sll;
  bool expected = true;
  bool actual = sll.empty();
  EXPECT_EQ(expected, actual);
}

// TEST(SINGLY_LINKED_LIST_TEST, EMPTY_TRUE)
// {
//     SinglyLinkedList sll;
//     bool expected = true;
//     bool actual = sll.empty();
//     EXPECT_EQ(expected, actual);
// }

TEST(SINGLY_LINKED_LIST_TEST, SIZE_EMPTY)
{
  SinglyLinkedList sll;
  int expected = 0;
  int actual = sll.size();
  EXPECT_EQ(expected, actual);
}

// TEST(SINGLY_LINKED_LIST_TEST, SIZE_POPULATED)
// {
//     SinglyLinkedList sll;
//     int expected = 0;
//     int actual = sll.size();
//     EXPECT_EQ(expected, actual);
// }

// TEST(SINGLY_LINKED_LIST_TEST, SIZE_CYCLIC)
// {
//     SinglyLinkedList sll;
//     int expected = 0;
//     int actual = sll.size();
//     EXPECT_EQ(expected, actual);
// }

TEST(SINGLY_LINKED_LIST_TEST, PUSH_BACK_EMPTY)
{
  printf("hello?\n");
  SinglyLinkedList sll;
  // sll.push_back(1);
  int actual = sll.back();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, PUSH_BACK_POPULATED)
{
  SinglyLinkedList sll;
  sll.push_back(1);
  sll.push_back(2);
  int actual = sll.back();
  int expected = 2;
  EXPECT_EQ(expected, actual);
}