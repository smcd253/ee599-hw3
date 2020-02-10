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
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, DEFAULT_CONSTRUCTOR_DYNAMIC)
{
  SinglyLinkedList* sll = new SinglyLinkedList();
  std::pair<ListNode*, int> expected(nullptr, 0);
  std::pair<ListNode*, int> actual(sll->head_, sll->size());
  EXPECT_EQ(expected, actual);
  delete sll;
}

TEST(SINGLY_LINKED_LIST_TEST, VECTOR_CONSTRUCTOR)
{
  const std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  SinglyLinkedList sll(vector, 2);
  std::pair<int, int> expected(2, 10);
  std::pair<int, int> actual(sll.tail_->next->val, sll.size());
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, VECTOR_CONSTRUCTOR_EMPTY_VECTOR)
{
  const std::vector<int> vector = {};
  SinglyLinkedList sll(vector, 2);
  std::pair<ListNode*, int> expected(nullptr, 0);
  std::pair<ListNode*, int> actual(sll.head_, sll.size());
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, VECTOR_CONSTRUCTOR_OUT_OF_BOUNDS)
{
  const std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  SinglyLinkedList sll(vector, 11);
  std::pair<ListNode*, int> expected(nullptr, 10);
  std::pair<ListNode*, int> actual(sll.tail_->next, sll.size());
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, VECTOR_CONSTRUCTOR_CYCLIC)
{
  const std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  SinglyLinkedList sll(vector, 0);
  std::pair<ListNode*, int> expected(sll.head_, 10);
  std::pair<ListNode*, int> actual(sll.tail_->next, sll.size());
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, VECTOR_CONSTRUCTOR_SINGLETON)
{
  const std::vector<int> vector = {0};
  SinglyLinkedList sll(vector, 0);
  std::pair<ListNode*, int> expected(sll.head_, 1);
  std::pair<ListNode*, int> actual(sll.tail_->next, sll.size());
  EXPECT_EQ(expected, actual);
}

// to be used with valgrind to test for memory leaks
TEST(SINGLY_LINKED_LIST_TEST, DESTRUCTOR)
{
  SinglyLinkedList* sll = new SinglyLinkedList();
  sll->push_front(1);
  ListNode* elem = sll->GetBackPointer();
  int val = elem->val;
  delete sll;
}

TEST(SINGLY_LINKED_LIST_TEST, EMPTY_TRUE)
{
  SinglyLinkedList sll;
  bool expected = true;
  bool actual = sll.empty();
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, EMPTY_FALSE)
{
    SinglyLinkedList sll;;
    sll.push_back(1);
    bool expected = false;
    bool actual = sll.empty();
    EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, SIZE_EMPTY)
{
  SinglyLinkedList sll;
  int expected = 0;
  int actual = sll.size();
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, SIZE_POPULATED)
{
    SinglyLinkedList sll;
    sll.push_back(1);
    int expected = 1;
    int actual = sll.size();
    EXPECT_EQ(expected, actual);
}

// TEST(SINGLY_LINKED_LIST_TEST, SIZE_CYCLIC)
// {
//     SinglyLinkedList sll;
//     int expected = 0;
//     int actual = sll.size();
//     EXPECT_EQ(expected, actual);
// }

TEST(SINGLY_LINKED_LIST_TEST, PUSH_BACK_EMPTY)
{
  SinglyLinkedList sll;
  sll.push_back(1);
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

TEST(SINGLY_LINKED_LIST_TEST, PUSH_FRONT_EMPTY)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  int actual = sll.front();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, PUSH_FRONT_POPULATED)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  int actual = sll.front();
  int expected = 2;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, INSERT_AFTER_EMPTY)
{
  SinglyLinkedList sll;
  sll.insert_after(sll.head_, 1);
  int actual = sll.back();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, INSERT_AFTER_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.insert_after(sll.head_, 2);
  int actual = sll.back();
  int expected = 2;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, INSERT_AFTER_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  sll.insert_after(sll.head_->next, 99);
  ListNode* result = sll.GetIthPointer(2);
  int actual = result->val;
  int expected = 99;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, ERASE_EMPTY)
{
  SinglyLinkedList sll;
  testing::internal::CaptureStdout();
  sll.erase(sll.head_);
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "List Empty. Nothing to erase.\n";
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, ERASE_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.erase(sll.head_);
  int actual = sll.size();
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, ERASE_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  sll.erase(sll.head_->next);
  int actual = sll.head_->next->val;
  int expected = 2;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, POP_FRONT_EMPTY)
{
  SinglyLinkedList sll;
  testing::internal::CaptureStdout();
  sll.pop_front();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "List Empty. Nothing to pop.\n";
  EXPECT_EQ(expected, actual);
}
  
TEST(SINGLY_LINKED_LIST_TEST, POP_FRONT_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.pop_front();
  int actual = sll.size();
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, POP_FRONT_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  sll.pop_front();
  int actual = sll.head_->val;
  int expected = 3;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, POP_BACK_EMPTY)
{
  SinglyLinkedList sll;
  testing::internal::CaptureStdout();
  sll.pop_back();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "List Empty. Nothing to pop.\n";
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, POP_BACK_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.pop_back();
  int actual = sll.size();
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, POP_BACK_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_back(1);
  sll.push_back(2);
  sll.push_back(3);
  sll.push_back(4);
  sll.pop_back();
  int actual = sll.head_->next->next->val;
  int expected = 3;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, BACK_EMPTY)
{
  SinglyLinkedList sll;
  int actual = sll.back();
  int expected = -1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, BACK_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  int actual = sll.back();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, BACK_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  int actual = sll.back();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, FRONT_EMPTY)
{
  SinglyLinkedList sll;
  int actual = sll.front();
  int expected = -1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, FRONT_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  int actual = sll.front();
  int expected = 1;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, FRONT_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  int actual = sll.front();
  int expected = 4;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, GET_BACK_POINTER_EMPTY)
{
  SinglyLinkedList sll;
  ListNode* actual = sll.GetBackPointer();
  ListNode* expected = nullptr;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, GET_BACK_POINTER_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  ListNode* actual = sll.GetBackPointer();
  ListNode* expected = sll.head_;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, GET_BACK_POINTER_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  ListNode* actual = sll.GetBackPointer();
  ListNode* expected = sll.head_->next->next->next;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, GET_ITH_POINTER_EMPTY)
{
  SinglyLinkedList sll;
  ListNode* actual = sll.GetIthPointer(0);
  ListNode* expected = nullptr;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, GET_ITH_POINTER_POPULATED_SINGULAR)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  ListNode* actual = sll.GetIthPointer(0);
  ListNode* expected = sll.head_;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, GET_ITH_POINTER_POPULATED_PLURAL)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  ListNode* actual = sll.GetIthPointer(2);
  ListNode* expected = sll.head_->next->next;
  EXPECT_EQ(expected, actual);
}

TEST(SINGLY_LINKED_LIST_TEST, PRINT)
{
  SinglyLinkedList sll;
  sll.push_front(1);
  sll.push_front(2);
  sll.push_front(3);
  sll.push_front(4);
  testing::internal::CaptureStdout();
  sll.print();
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expected = "{4, 3, 2, 1}\n";
  EXPECT_EQ(expected, actual);
}
