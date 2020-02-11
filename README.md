# ee599-hw3 - Linked Lists, Stacks, and Queues
Created - Spencer McDonough : 02/03/2020
Last Modified - Spencer McDonough : 02/11/2020
University of Southern California


## Q1 - Pros and Cons of Various Parameter Options

**Passing by Value**
- Pros
    - Easy and straightforward
    - Creates a local copy --> can manipulate the variable in the function's scope without affecting the source data
- Cons
    - Creats a local copy --> uses more memory and takes more time
    - Impractical for large variables (see above)
- Preferred Use: When you want to use a small datatype to do some calculations, but do not want to change the parameter passed in by the client program.
Ex:
```
int tax(int income, int rate)
{
    return income*rate;
}
```

**Passing using Pointers**
- Pros
    - Only passing a value holding the memory location --> uses a constant, small amount of memory
    - Can manipulate source data outside the scope of its declaration
- Cons
    - Must dereference to access value
    - Possible to receive nullptr or garbage data, easily braking code if not careful
    - Can corrupt source data if not careful
- Preferred Use: Passing arrays to a function is more memory efficient and good for iterating when passing using a pointer.
Ex:
```
void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = tem[;]
}
```

**Passing using References**
- Pros
    - Only passing a value holding the memory location --> uses a constant, small amount of memory
    - Can manipulate source data outside the scope of its declaration
    - This is the *actual* memory location, and not just a pointer to it, so we do not run the risk of getting a nullptr or garbage data. Any error like this will be caught at compile time
- Cons
    - Can corrupt source data if not careful
- Preferred Use: When you want to use a function to modify the parameter passed by the client program without returning a new type.
Ex:
```
void growth(int& balance, int rate)
{
    balance += balance*rate;
}
```

**Passing using const References**
- Pros
    - Only passing a value holding the memory location --> uses a constant, small amount of memory
    - Can manipulate source data outside the scope of its declaration
    - This is the *actual* memory location, and not just a pointer to it, so we do not run the risk of getting a nullptr or garbage data. Any error like this will be caught at compile time
    - Const ensures that we *do not* corrupt the source data
- Cons
    - Source data is immutable
- Preferred Use: When you want to do some calculations based on a client parameter usually too large for pass by value;

Ex:
```
double gpa(const AcademicRecord& student1)
{
    double gpa = 0;
    for (auto n : student1.classes)
    {
        gpa += n.gpa/n.units;
    }
    return gpa;
}
```
## Q2 - Mapping Values to their Indices
**Compile Instructions**
Run Sample Code:
```
bazel run src/main:main
```

Run Unit Tests:
```
bazel run tests:tests
// or
bazel test tests:tests
```

**Runtime Analysis**
Runtime = &theta;(3 + n*log(n) + n^2) --> O(n^2)

## Q3 - Singly Linked List
**Compile Instructions**
Run Sample Code:
```
bazel run src/main:main
```

Run Unit Tests:
```
bazel run tests:tests
// or
bazel test tests:tests
// to test for memory leaks
bazel run --run_under=valgrind tests:tests
```

note: to install valgrind on a Linux-based operating system run `sudo apt-get install valgrind` <br> <br>

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
**Compile Instructions**
Run Sample Code:
```
bazel run src/main:main
```

Run Unit Tests:
```
bazel run tests:tests
// or
bazel test tests:tests
```

**Runtime Analysis**

```
bool Solution::valid_brackets(std::string input)
```
Runtime = &theta;(2 + (1 + 3 + 7)n + 3) --> O(n)

## Q5 - Class Academic Record
**Compile Instructions**
Run Sample Code:
```
bazel run src/main:main
```

Run Unit Tests:
```
bazel run tests:tests
// or
bazel test tests:tests
```

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

## Q6 - Interactive Vector Reader
**Compile Instructions**
First, `cd` into q6-vect_reader/main/ and modify the args value to be the path of output.txt. This can be done by right clicking on the output file and selecting "copy path."
Then `cd ..` and run sample code:
```
bazel run src/main:main
```

**Execution Instruction**
You will be given the following prompt:
```
Enter 1 for user input or 2 for pre-defined input:
```
Enter `2` to generate the output file based on the provided input sequence in the assignment prompt.
Enter `1` for custom input.

**Runtime Analysis of Functions**

```
void vector_interact::print_menu(FILE* f)
```
Runtime = &theta;(4 + 5n) --> O(n)

```
void vector_interact::print_result(FILE* f, int usr_in)
```
Runtime = &theta;(16) --> O(1)

**Runtime Analysis of Menu Options**
Menu Item1: Runtime = &theta;(4) --> O(1)
Menu Item2: Runtime = &theta;(6) --> O(1)
Menu Item3: Runtime = &theta;(5) --> O(1)
Menu Item4: Runtime = &theta;(12) --> O(1)
Menu Item4: Runtime = &theta;(4) --> O(1)
