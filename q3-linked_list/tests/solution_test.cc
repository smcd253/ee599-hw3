#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
#include <utility>

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

TEST(SINGLY_LINKED_LIST_TEST, SIZE)
{
    SinglyLinkedList sll;
    int expected = 0;
    int actual = sll.size();
    EXPECT_EQ(expected, actual);
}