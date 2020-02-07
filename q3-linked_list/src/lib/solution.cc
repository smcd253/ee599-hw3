#include "solution.h"

// Runtime = 3 --> O(1)
void SinglyLinkedList::new_head_tail(int i)
{
    this->head_ = new ListNode(i);
    this->head_->next = nullptr;
    this->tail_ = this->head_;
}

// Runtime = 1 --> O(1)
bool SinglyLinkedList::empty()
{
    return (this->list_size == 0);
}

// Runtime = 1 --> O(1)
int SinglyLinkedList::size()
{
    return this->list_size;
}

// Runtime = 5 --> O(1)
void SinglyLinkedList::push_back(int i)
{
    if(this->tail_ != nullptr)
    {
        ListNode* n = new ListNode(i);
        this->tail_->next = n;
        this->tail_ = n;
    }
    else
    {
        this->new_head_tail(i);
    }
    this->list_size++;
}

// Runtime = 5 --> O(1)
void SinglyLinkedList::push_front(int i)
{
    if(this->head_ != nullptr)
    {
        ListNode* n = new ListNode(i);
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
// Runtime = 7 --> O(1)
void SinglyLinkedList::insert_after(ListNode* p, int i)
{
    if(this->head_ != nullptr)
    {
        ListNode* n = new ListNode(i);
        n->next = p->next;
        p->next = n;
        if(n->next == nullptr)
        {
            this->tail_ = n;
        }
    }
    else
    {
        this->new_head_tail(i);
    }
    this->list_size++;
}

// Runtime = 3 + n + 4 --> O(n)
void SinglyLinkedList::erase(ListNode* p)
{
    if(this->head_ != nullptr)
    {
        ListNode* n = this->head_; 
        // if p is not the head 
        if (n != p)
        {
            // iterate over list
            while(n->next != p)
            {
                n = n->next;
            }
            // point n->next to p->next to remove p from list
            n->next = p->next;
            // clean up old node
            p->next = nullptr;
        }   
        // else if p is the head
        else
        {
            // if p is not the only node
            if(n->next != nullptr)
            {
                // move n to the new head
                n = n->next;
                // clean up old head
                this->head_->next = nullptr;
                // move head to new position
                this->head_ = n;
                
                // if the new head is now the only element, point the tail here too
                if(n->next == nullptr)
                {
                    this->tail_ = n;
                }
            }
            else
            {
                this->head_ = nullptr;
                this->head_ = nullptr;
            }
        }
        delete p;
        this->list_size--;
    }
    else
    {
        printf("List Empty. Nothing to erase.\n");
    }
}

// Runtime = 6 --> O(1)
void SinglyLinkedList::pop_front()
{
    if(this->head_ != nullptr)
    {
        ListNode* n = this->head_;
        this->head_ = this->head_->next;
        n->next = nullptr;
        delete n;
        this->list_size--;
    }
    else
    {
        printf("List Empty. Nothing to pop.\n");
    }
}

// Runtime = 3 + n + 5 --> O(n)
void SinglyLinkedList::pop_back()
{
    if(this->tail_ != nullptr)
    {
        ListNode* n = this->head_;
        if(this->tail_ != this->head_)
        {
            
            while(n->next != this->tail_)
            {
                n = n->next;
            }
            this->tail_ = n;
            n = n->next;
            this->tail_->next = nullptr;
        }
        else
        {
            this->tail_ = nullptr;
            this->head_ = nullptr;
        }
        delete n;
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

// Runtime = 2 + n + 1 --> O(n)
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
        while (n != nullptr)
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
