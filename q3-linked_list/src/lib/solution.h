#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <iostream> // for debugging

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class SinglyLinkedList 
{
private:
    int list_size; // internal size variable to amortize size()
    void new_head_tail(int i); // internal function to initialize a list with its first element
public:
    // default constructor
    // Runtime = 3 --> O(1)
    SinglyLinkedList()
    {
        // initialize ListNode
        head_ = nullptr;
        tail_ = nullptr;    
        list_size = 0;
    }

    // Creates a linked list out of vector “inputs” and connects the last
    /**
    item’s next to i(th) item in the list.
    - If i is -1, the last item’s next is nullptr.
    - If i is greater than input size, the last item’s next is nullptr.
    */
    // Runtime = 2 + 7n + 2 --> O(n)
    SinglyLinkedList(const std::vector<int> &inputs, int i)
    {
        if((int)inputs.size() > 0 && i >=-1)
        {            
            ListNode* con_pt = nullptr;
            for (int k = (int)inputs.size() - 1; k >= 0; k--)
            {   
                ListNode* n = new ListNode(inputs[k]);
                if(k == (int)inputs.size() - 1)
                {
                    head_ = n;
                    tail_ = head_;
                    head_->next = nullptr;
                }
                else
                {
                    n->next = head_;
                    head_ = n;
                }

                list_size++;

                if(k == i)
                {
                    con_pt = n;
                }
            }

            tail_->next = con_pt;
        }
        else
        {
            head_ = nullptr;
            tail_ = nullptr;    
            list_size = 0;
        }
    }

    // destructor, cleans up

    ~SinglyLinkedList() 
    {
        while(!this->empty())
        {
            this->pop_front();
        } 
    }   
    bool empty(); // checks if empty
    int size(); // returns size
    void push_back(int i); // inserts at the back
    void push_front(int i); // inserts at the front
    void insert_after(ListNode* p, int i); // inserts value i after p
    void erase(ListNode* p); // Erases node p
    void pop_front(); // removes the first item
    void pop_back(); // removes the last item
    int back(); // returns the value of last item
    int front(); // returns the value of first item
    ListNode *GetBackPointer(); // Returns pointer to last item

    // Returns pointer to i(th) element
    ListNode *GetIthPointer(int i);

    // Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
    void print();

    ListNode* head_; // Pointer to the first element
    ListNode* tail_; // Pointer to the last element to amortize push_back() and back()

};
#endif