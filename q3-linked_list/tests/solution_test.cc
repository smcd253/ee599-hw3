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

TEST(SINGLY_LINKED_LIST_TEST, DESTRUCTOR)
{
    SinglyLinkedList* sll = new SinglyLinkedList();
    delete sll;

    SinglyLinkedList* expected = nullptr;

    EXPECT_EQ(expected, sll);
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
    printf("back = %d\n", sll.back());
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
  sll.erase(sll.head_);
  int actual = sll.size();
  int expected = 0;
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
  sll.pop_front();
  int actual = sll.size();
  int expected = 0;
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
  sll.pop_back();
  int actual = sll.size();
  int expected = 0;
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
