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
&theta;()