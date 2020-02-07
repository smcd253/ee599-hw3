#include "solution.h"

void SinglyLinkedList::new_head_tail(int i)
{
  this->head_->val = i;
  this->head_->next = nullptr;
  this->tail_ = this->head_;
}

// Runtime = O(1)
bool SinglyLinkedList::empty()
{
  return (this->list_size == 0);
}

// Runtime = 1 --> O(1)
int SinglyLinkedList::size()
{
    return this->list_size;
}

// Runtime = 6 --> O(1)
void SinglyLinkedList::push_back(int i)
{
  if(this->tail_ != nullptr)
  {
    printf("ah\n");
    ListNode* n = nullptr;
    printf("ah\n");

    n->val = i;
    this->tail_->next = n;
    this->tail_ = n;
  }
  else
  {
    printf("else\n");

    // this->new_head_tail(i);
    printf("else\n");
  }
  this->list_size++;
}

// Runtime = 5 --> O(1)
void SinglyLinkedList::push_front(int i)
{
  if(this->head_ != nullptr)
  {
    ListNode* n = nullptr;
    n->val = i;
    n->next = this->head_;
    this->head_ = n;
  }
  else
  {
    this->new_head_tail(i);
  }
  this->list_size++;
}

// Note: does not check if input node is part of this list.
// Runtime = 5 --> O(1)
void SinglyLinkedList::insert_after(ListNode* p, int i)
{
  if(this->head_ != nullptr)
  {
    ListNode* n = nullptr;
    n->val = i;
    n->next = p->next;
    p->next = n;
  }
  else
  {
    this->new_head_tail(i);
  }
  this->list_size++;
}

// Runtime = 2 + n + 3 --> O(n)
void SinglyLinkedList::erase(ListNode* p)
{
  if(this->head_ != nullptr)
  {
    ListNode* iterator = this->head_; 
    // iterate over list
    while(iterator->next != p)
    {
      iterator = iterator->next;
    }
    iterator->next = p->next;
    p->next = nullptr;
    this->list_size--;
  }
  else
  {
    printf("List Empty. Nothing to erase.\n");
  }
}

// Runtime = 5 --> O(1)
void SinglyLinkedList::pop_front()
{
  if(this->head_ != nullptr)
  {
    ListNode* n = this->head_;
    this->head_ = this->head_->next;
    n->next = nullptr;
    this->list_size--;
  }
  else
  {
    printf("List Empty. Nothing to pop.\n");
  }
}

// Runtime = 2 + n + 2 --> O(n)
void SinglyLinkedList::pop_back()
{
  if(this->tail_ != nullptr)
  {
    ListNode* n = this->head_;
    while(n->next != this->tail_)
    {
      n = n->next;
    }
    n->next = nullptr;
    this->list_size--;
  }
  else
  {
    printf("List Empty. Nothing to pop.\n");
  }
}

// Runtime = 2 --> O(1)
int SinglyLinkedList::back()
{
  if(this->tail_ != nullptr)
  {
    return this->tail_->val;
  }
  else
  {
    printf("List Empty. No value to return.\n");
    return -1;
  }
}

// Runtime = 2 --> O(1)
int SinglyLinkedList::front()
{
  if(this->head_ != nullptr)
  {
    return this->head_->val;
  }
  else
  {
    printf("List Empty. No value to return.\n");
    return -1;
  }
}

// Runtime = 1 --> O(1)
ListNode* SinglyLinkedList::GetBackPointer()
{
  return this->tail_;
}

// Runtime = 2 + i + 1 --> O(n)
ListNode* SinglyLinkedList::GetIthPointer(int i)
{
  if (this->head_ != nullptr)
  {
    ListNode* n = this->head_;
    for (int _i = 0; _i < i; _i++)
    {
      n = n->next;
    }
    return n;
  }
  else
  {
    return nullptr;
  }
}

// Runtime = 3 + 3n --> O(n)
void SinglyLinkedList::print()
{
  if (this->head_ != nullptr)
  {
    ListNode* n = this->head_;
    printf("{");
    while (n->next != nullptr)
    {
      if (n->next != nullptr)
      {
        printf("%d, ", n->val);
      }
      else
      {
        printf("%d}\n", n->val);
      }
      n = n->next;
    }
  }
  else
  {
    printf("{}\n");
  }
}