# ee599-hw3
Linked Lists, Stacks, and Queues

## Q1 - Pros and Cons of Various Parameter Options

**Passing by Value**
- Pros
    - Easy and straightforward
    - Creates a local copy --> can manipulate the variable in the function's scope without affecting the source data
- Cons
    - Creats a local copy --> uses more memory and takes more time
    - Impractical for large variables (see above)

**Passing using Pointers**
- Pros
    - Only passing a value holding the memory location --> uses a constant, small amount of memory
    - Can manipulate source data outside the scope of its declaration
- Cons
    - Must dereference to access value
    - Possible to receive nullptr or garbage data, easily braking code if not careful
    - Can corrupt source data if not careful

**Passing using References**
- Pros
    - Only passing a value holding the memory location --> uses a constant, small amount of memory
    - Can manipulate source data outside the scope of its declaration
    - This is the *actual* memory location, and not just a pointer to it, so we do not run the risk of getting a nullptr or garbage data. Any error like this will be caught at compile time
- Cons
    - Can corrupt source data if not careful

**Passing using const References**
- Pros
    - Only passing a value holding the memory location --> uses a constant, small amount of memory
    - Can manipulate source data outside the scope of its declaration
    - This is the *actual* memory location, and not just a pointer to it, so we do not run the risk of getting a nullptr or garbage data. Any error like this will be caught at compile time
    - Const ensures that we *do not* corrupt the source data
- Cons
    - Source data is immutable

## Q2 - Mapping Values to their Indices

**Runtime Analysis**
Runtime = &theta;(3 + n*log(n) + n^2) --> O(n^2)

## Q3 - Singly Linked List
**Runtime Analysis**

```
SinglyLinkedList()
```
Runtime = &theta;(3) --> O(1)

```
SinglyLinkedList(const std::vector<int> &inputs, int i)
```
Runtime = &theta;(2 + 7n + 2) --> O(n)

```
bool SinglyLinkedList::empty()
```
Runtime = &theta;(1) --> O(1)

```
int SinglyLinkedList::size()
```
Runtime = &theta;(1) --> O(1)

```
void SinglyLinkedList::push_back(int i)
```
Runtime = &theta;(5) --> O(1)

```
void SinglyLinkedList::push_front(int i)
```
Runtime = &theta;(5) --> O(1)

```
void SinglyLinkedList::insert_after(ListNode* p, int i)
```
Runtime = &theta;(7) --> O(1)

```
void SinglyLinkedList::erase(ListNode* p)
```
Runtime = &theta;(3 + n + 4) --> O(n)

```
void SinglyLinkedList::pop_front()
```
Runtime = &theta;(6) --> O(1)

```
void SinglyLinkedList::insert_after(ListNode* p, int i)
```
Runtime = &theta;(7) --> O(1)

```
void SinglyLinkedList::erase(ListNode* p)
```
Runtime = &theta;(3 + n + 4) --> O(n)

```
void SinglyLinkedList::pop_front()
```
Runtime = &theta;(6) --> O(1)

```
void SinglyLinkedList::pop_back()
```
Runtime = &theta;(3 + n + 5) --> O(n)

```
int SinglyLinkedList::back()
```
Runtime = &theta;(2) --> O(1)

```
int SinglyLinkedList::front()
```
Runtime = &theta;(2) --> O(1)

```
ListNode* SinglyLinkedList::GetBackPointer()
```
Runtime = &theta;(1) --> O(1)

```
ListNode* SinglyLinkedList::GetIthPointer(int i)
```
Runtime = &theta;(2 + n + 1) --> O(n)

```
void SinglyLinkedList::print()
```
Runtime = &theta;(3 + 3n) --> O(n)

## Q4 - Valid Brackets
**Runtime Analysis**

```
bool Solution::valid_brackets(std::string input)
```
Runtime = &theta;(2 + (2 + 4 + 7)n + 3) --> O(n)

## Q5 - Class Academic Record
**Runtime Analysis**

```
AcademicRecord() : max_grade(100), min_grade(0), math(0), computers(0), physics(0) {}
```
Runtime = &theta;(5) --> O(1)

```
AcademicRecord(int x, int y, int z) : max_grade(100), min_grade(0), math(x), computers(y), physics(z) {}
```
Runtime = &theta;(5) --> O(1)

```
AcademicRecord(const AcademicRecord& src)
```
Runtime = &theta;(6) --> O(1)

```
AcademicRecord& operator=(const AcademicRecord& rhs)
```
Runtime = &theta;(6) --> O(1)

```
void AcademicRecord::check_bounds()
```
Runtime = &theta;(6) --> O(1)

```
AcademicRecord operator++()
```
Runtime =  &theta;(3 + 6 + 1) --> O(1)

```
AcademicRecord operator++(int)
```
Runtime =  &theta;(3 + 6 + 1) --> O(1)

```
AcademicRecord operator--()
```
Runtime =  &theta;(3 + 6 + 1) --> O(1)

```
AcademicRecord operator--(int)
```
Runtime =  &theta;(3 + 6 + 1) --> O(1)

```
AcademicRecord operator+=(int i)
```
Runtime =  &theta;(3 + 6 + 1) --> O(1)

```
AcademicRecord operator-=(int i)
```
Runtime =  &theta;(3 + 6 + 1) --> O(1)

```
bool operator==(const AcademicRecord& rhs)
```
Runtime =  &theta;(11) --> O(1)

```
std::string print() const;
```
Runtime =  &theta;(4 + 36 + 2) --> O(1)

