#include <iostream>
#include "src/lib/solution.h"

int main()
{
    // test default constructor
    SinglyLinkedList* sll = new SinglyLinkedList();
    printf("list size = %d\n", (int)sll->size());
    
    int item = 1;
    printf("push item = %d to front of linked list.\n", item);
    sll->push_front(item);
    printf("SinglyLinkedList::front() = %d\n", sll->front());
    item = 2;
    printf("push item = %d to back of linked list.\n", item);
    sll->push_back(item);
    printf("SinglyLinkedList::back() = %d\n", sll->back());
    printf("Here is our whole list:\n");
    sll->print();
    delete sll;

    printf("Let's build a cyclic linked list now!\n");
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList* cyclic = new SinglyLinkedList(v, 0);
    printf("Now the head and tail should be the same!\n");
    printf("SinglyLinkedList::head_->val = %d\n", cyclic->head_->val);
    printf("SinglyLinkedList::tail_->val = %d\n", cyclic->tail_->val);
    printf("And the size of our list and the size of the input vector should be the same.\n");
    printf("SinglyLinkedList::size() = %d\n", (int)cyclic->size());
    printf("std::vector<int>::size() = %d\n", (int)v.size());
    printf("Here is our whole list:\n");
    cyclic->print();
    int index = 4;
    ListNode* node = cyclic->GetIthPointer(index);
    printf("Let's try removing the node at index %d with value %d\n",index, node->val);
    cyclic->erase(node);
    printf("Now the node at index %d should have value %d\n", index, 5);
    node = cyclic->GetIthPointer(index);
    printf("SinglyLinkedList::GetIthPointer(%d)->val = %d\n", index, node->val);
    printf("SinglyLinkedList::size() = %d\n", (int)cyclic->size());
    printf("Here is our whole list:\n");
    cyclic->print();
    delete cyclic;

    return EXIT_SUCCESS;
}