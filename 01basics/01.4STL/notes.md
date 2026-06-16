# Standard Template Library (STL)

## Definition

The C++ Standard Template Library (STL) is a collection of template classes and functions that provide general-purpose algorithms, containers, iterators, and function objects.

---

### C++ Skeleton

```cpp
// Method 1 - Includes all standard libraries (convenient for competitive programming)
#include <bits/stdc++.h>

// Method 2 - Include only what you need (preferred in production code)
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    return 0;
}
```

---

### Functions

**1. Void Function** — performs an action, returns nothing
```cpp
void print() {
    cout << "Hello";
}
```

**2. Return-Type Function** — returns a value of the specified type
```cpp
int sum(int a, int b) {
    return a + b;
}
```

---

### C++ STL — 4 Components

| Component      | Description                                              |
|----------------|----------------------------------------------------------|
| **Algorithms** | Sorting, searching, manipulating ranges (`sort`, `find`) |
| **Containers** | Data structures (`vector`, `map`, `set`, `stack`, etc.)  |
| **Functions**  | Function objects / functors used with algorithms         |
| **Iterators**  | Pointers to traverse container elements                  |

---

### Pairs

`std::pair` stores two values of (possibly different) types together.

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainPairs() {

    // 1. Simple pair
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second;
    // Output: 1 2

    // 2. Nested pair (pair within a pair)
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second;
    // Output: 1 3 4

    // 3. Array of pairs
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[2].first;
    // Output: 5

}
```
# Containers

## What are Containers?

Containers are STL classes that store collections of objects. Each container manages its own memory and provides different performance trade-offs depending on the use case.

| Category               | Examples                                  |
|------------------------|-------------------------------------------|
| **Sequence Containers**    | `vector`, `deque`, `list`, `array`        |
| **Associative Containers** | `map`, `set`, `multimap`, `multiset`      |
| **Unordered Containers**   | `unordered_map`, `unordered_set`          |
| **Container Adaptors**     | `stack`, `queue`, `priority_queue`        |
| **Utility** *(not a container)* | `pair`, `tuple`                    |

---

## 1. Vectors

### What is a Vector and Why Do We Need It?

A `vector` is a **dynamic array** — unlike a plain array, it can grow and shrink in size automatically at runtime. It stores elements in **contiguous memory**, making random access fast `O(1)` and cache-friendly.

| Feature          | Plain Array      | Vector               |
|------------------|------------------|----------------------|
| Size             | Fixed at compile | Dynamic at runtime   |
| Memory           | Stack            | Heap (managed)       |
| Bounds checking  | ❌ None          | ✅ via `.at()`       |
| Built-in methods | ❌ None          | ✅ sort, insert, erase, etc. |

---

### Declaration & Initialisation

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainVector() {

    // Empty vector
    vector<int> v;              // {}

    // Adding elements
    v.push_back(1);             // {1}
    v.push_back(2);             // {1, 2}
    v.emplace_back(3);          // {1, 2, 3}
    // emplace_back constructs the element in-place, avoiding an
    // extra copy/move — slightly faster than push_back.

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});      // push_back needs explicit braces
    vec.emplace_back(1, 2);     // emplace_back constructs in-place, no braces needed

    // Initialisation with size and default value
    vector<int> a(5, 100);      // {100, 100, 100, 100, 100}
    vector<int> b(5);           // {0, 0, 0, 0, 0}  ← default initialised to 0

    // Copy constructor
    vector<int> v1(5, 20);      // {20, 20, 20, 20, 20}
    vector<int> v2(v1);         // {20, 20, 20, 20, 20}  ← deep copy of v1
}
```

---

### Accessing Elements

#### Method 1 — Index-based

```cpp
vector<int> v = {10, 20, 30, 40, 50};

cout << v[3];      // Output: 40  — no bounds check (unsafe if out of range)
cout << v.at(3);   // Output: 40  — throws std::out_of_range if index is invalid
cout << v.front(); // Output: 10  — first element
cout << v.back();  // Output: 50  — last element
```

> ⚠️ Prefer `v.at(i)` over `v[i]` when you're unsure about the index range — it catches bugs at runtime instead of causing undefined behaviour.

---

#### Method 2 — Iterators

An iterator is like a pointer that points to a position inside a container.

```
Index:     0    1    2    3    4
Vector:  { 10,  20,  30,  40,  50 }
           ↑                    ↑    ↑
        begin()              back() end()   ← ONE past the last element

Reverse: { 10,  20,  30,  40,  50 }
          ↑ ↑
      rend() rbegin()                       ← rbegin points at 50
```

```cpp
vector<int> v = {10, 20, 30, 40, 50};

vector<int>::iterator it = v.begin();  // Points to first element (10)
cout << *it;                           // Output: 10
it++;
cout << *it;                           // Output: 20

// Key iterator positions:
// v.begin()  → first element (10)
// v.end()    → ONE past last element — never dereference this!
// v.rbegin() → last element (50)
// v.rend()   → ONE before first element — never dereference this!
```

---

### Printing a Vector

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// Method 1: Explicit iterator
for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Method 2: auto iterator (cleaner)
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Method 3: Range-based for loop (simplest — preferred)
for (auto element : v) {
    cout << element << " ";
}

// All three output: 10 20 30 40 50
```

---

### Erasing Elements

`erase()` removes element(s) by iterator position. The range version follows **[start, end)** — the end iterator is **not** deleted.

```cpp
// Single element erase
vector<int> v = {10, 20, 30, 40};
v.erase(v.begin() + 1);
// Removed index 1 (20) → {10, 30, 40}

// Range erase  [begin+1, begin+4)  →  removes indices 1, 2, 3
vector<int> v2 = {10, 20, 30, 40, 50, 60};
v2.erase(v2.begin() + 1, v2.begin() + 4);
// Removed 20, 30, 40 → {10, 50, 60}
```

> 💡 `erase` range is **[start, end)** — the element at `end` is **not** removed.

---

### Inserting Elements

```cpp
vector<int> v(2, 100);          // {100, 100}

v.insert(v.begin(), 300);       // Insert 300 at index 0  → {300, 100, 100}

v.insert(v.begin() + 2, 3, 10); // Insert 10 three times at index 2
                                 // → {300, 100, 10, 10, 10, 100}
```

---

### Copying One Vector into Another

```cpp
vector<int> copy(3, 50);        // {50, 50, 50}

// Insert all elements of 'copy' at the beginning of v
v.insert(v.begin(), copy.begin(), copy.end());
// v → {50, 50, 50, 300, 100, 10, 10, 10, 100}
```

---

### Other Important Methods

```cpp
// Assume v = {50, 50, 50, 300, 100, 10, 10, 10, 100}

v.size();       // 9  — number of elements currently in the vector

v.pop_back();   // Removes the last element
                // v → {50, 50, 50, 300, 100, 10, 10, 10}

v.swap(copy);   // Swaps contents of v and copy
                // v → {50, 50, 50}   |   copy → {50, 50, 50, 300, 100, 10, 10, 10}

v.clear();      // Removes all elements
                // v → {}

v.empty();      // Returns true if vector is empty, false otherwise
                // true (since we just cleared it)
```

| Method          | What it does                                 | Returns     |
|-----------------|----------------------------------------------|-------------|
| `v.size()`      | Number of elements in the vector             | `size_t`    |
| `v.pop_back()`  | Removes last element                         | `void`      |
| `v.swap(other)` | Swaps contents with another vector           | `void`      |
| `v.clear()`     | Removes all elements (size → 0)              | `void`      |
| `v.empty()`     | Checks if vector is empty                    | `bool`      |# Vectors

## 2. Lists

### What is a List and Why Do We Need It?

A `list` in STL is a **doubly linked list** — each element holds a value and two pointers: one to the **next** node and one to the **previous** node. Unlike a vector, elements are **not stored in contiguous memory**.

```
┌─────────────────────────────────────────────────────────┐
│  NULL ← [6] ↔ [5] ↔ [2] ↔ [4] → NULL                 │
│          ↑                   ↑                          │
│        front()             back()                       │
└─────────────────────────────────────────────────────────┘
```

---

### How is List Different from Vector?

| Feature                  | `vector`                  | `list`                        |
|--------------------------|---------------------------|-------------------------------|
| Internal structure       | Dynamic array             | Doubly linked list            |
| Memory layout            | Contiguous                | Scattered (nodes on heap)     |
| Random access (`v[i]`)   | ✅ `O(1)`                 | ❌ Not supported              |
| Insert/Delete at middle  | ❌ Slow `O(n)` (shifting) | ✅ Fast `O(1)` (pointer swap) |
| Insert/Delete at front   | ❌ Slow `O(n)`            | ✅ Fast `O(1)`                |
| Insert/Delete at back    | ✅ Fast `O(1)`            | ✅ Fast `O(1)`                |
| Cache performance        | ✅ Great (contiguous)     | ❌ Poor (scattered memory)    |
| Iterators                | Random access iterator    | Bidirectional iterator only   |

> 💡 **Use a `list` when** you need frequent insertions/deletions in the **middle or front** of a sequence. Use a `vector` when you need fast **random access** or cache-friendly traversal.

---

### Declaration & Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainList() {

    list<int> ls;           // Empty list: {}

    // --- Adding at the back ---
    ls.push_back(2);        // {2}
    ls.emplace_back(4);     // {2, 4}

    // --- Adding at the front ---
    ls.push_front(5);       // {5, 2, 4}
    ls.emplace_front(6);    // {6, 5, 2, 4}
    // emplace_front / emplace_back construct in-place (faster than push variants)

    // --- Removing elements ---
    ls.pop_back();          // {6, 5, 2}    — removes last element
    ls.pop_front();         // {5, 2}       — removes first element

    // --- Access ---
    cout << ls.front();     // Output: 5    — first element
    cout << ls.back();      // Output: 2    — last element
    // ⚠️ No ls[i] or ls.at(i) — lists do NOT support random access

    // --- Size & empty check ---
    cout << ls.size();      // Output: 2
    cout << ls.empty();     // Output: 0 (false)

    // --- Insert at a position (using iterator) ---
    list<int> ls2 = {10, 20, 30, 40};
    auto it = ls2.begin();
    advance(it, 2);         // Move iterator to index 2 (points to 30)
    ls2.insert(it, 99);     // {10, 20, 99, 30, 40}

    // --- Erase at a position ---
    ls2.erase(it);          // Removes element at iterator position
                            // {10, 20, 99, 40}

    // --- Other shared methods (same behaviour as vector) ---
    // begin(), end(), rbegin(), rend() — for iteration
    // clear()                          — removes all elements
    // swap(other)                      — swaps two lists
}
```

---

### Printing a List

```cpp
list<int> ls = {6, 5, 2, 4};

// Range-based for loop (simplest)
for (auto element : ls) {
    cout << element << " ";
}
// Output: 6 5 2 4

// Using iterator
for (auto it = ls.begin(); it != ls.end(); it++) {
    cout << *it << " ";
}
// Output: 6 5 2 4
```

---

### Quick Reference

| Method              | Description                              |
|---------------------|------------------------------------------|
| `push_back(x)`      | Add `x` at the end                       |
| `push_front(x)`     | Add `x` at the beginning                 |
| `emplace_back(x)`   | Construct `x` in-place at the end        |
| `emplace_front(x)`  | Construct `x` in-place at the beginning  |
| `pop_back()`        | Remove last element                      |
| `pop_front()`       | Remove first element                     |
| `front()`           | Access first element                     |
| `back()`            | Access last element                      |
| `insert(it, x)`     | Insert `x` before iterator position      |
| `erase(it)`         | Remove element at iterator position      |
| `size()`            | Number of elements                       |
| `empty()`           | Returns `true` if list is empty          |
| `clear()`           | Remove all elements                      |
| `swap(other)`       | Swap contents with another list          |

## 3. Deque (Double-Ended Queue)

### What is a Deque and Why Do We Need It?

A `deque` (pronounced *"deck"*) stands for **Double-Ended Queue**. It is a sequence container that allows **fast insertion and deletion at both the front and the back** — something a `vector` cannot do efficiently.

Internally, a deque is stored as a **series of fixed-size chunks** (not a single contiguous block like a vector), which allows it to grow in both directions without shifting elements.

```
        push_front()                      push_back()
             ↓                                ↓
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  │ 6 │ 5 │ 2 │ 4 │   │   │   │   │   │   │
  └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
    ↑                 ↑
  front()           back()
```

---

### How is Deque Different from Vector and List?

| Feature                    | `vector`        | `list`          | `deque`              |
|----------------------------|-----------------|-----------------|----------------------|
| Internal structure         | Dynamic array   | Doubly linked   | Chunked array        |
| Insert/Delete at **back**  | ✅ `O(1)`       | ✅ `O(1)`       | ✅ `O(1)`            |
| Insert/Delete at **front** | ❌ `O(n)`       | ✅ `O(1)`       | ✅ `O(1)`            |
| Insert/Delete at **middle**| ❌ `O(n)`       | ✅ `O(1)`       | ❌ `O(n)`            |
| Random access (`dq[i]`)    | ✅ `O(1)`       | ❌ Not supported| ✅ `O(1)`            |
| Memory layout              | Contiguous      | Scattered       | Chunked (semi-contiguous) |
| Cache performance          | ✅ Best         | ❌ Poor         | ⚠️ Moderate          |

> 💡 **Use a `deque` when** you need fast insertions/deletions at **both ends** and still want **random access** — it's the best of both `vector` and `list` for this specific use case.

---

### Declaration & Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainDeque() {

    deque<int> dq;              // Empty deque: {}

    // --- Adding at the back ---
    dq.push_back(2);            // {2}
    dq.emplace_back(4);         // {2, 4}

    // --- Adding at the front ---
    dq.push_front(5);           // {5, 2, 4}
    dq.emplace_front(6);        // {6, 5, 2, 4}
    // emplace variants construct in-place — slightly faster than push variants

    // --- Removing elements ---
    dq.pop_back();              // {6, 5, 2}   — removes last element
    dq.pop_front();             // {5, 2}      — removes first element

    // --- Access ---
    cout << dq.front();         // Output: 5   — first element
    cout << dq.back();          // Output: 2   — last element
    cout << dq[0];              // Output: 5   — random access (unlike list, this works!)
    cout << dq.at(1);           // Output: 2   — safe random access with bounds check

    // --- Size & empty check ---
    cout << dq.size();          // Output: 2
    cout << dq.empty();         // Output: 0 (false)

    // --- Insert at a position (using iterator) ---
    deque<int> dq2 = {10, 20, 30, 40};
    dq2.insert(dq2.begin() + 2, 99);   // Insert 99 at index 2
                                        // {10, 20, 99, 30, 40}

    // --- Erase at a position ---
    dq2.erase(dq2.begin() + 1);        // Remove element at index 1
                                        // {10, 99, 30, 40}

    // --- Other shared methods (same behaviour as vector) ---
    // begin(), end(), rbegin(), rend() — for iteration
    // clear()                          — removes all elements
    // swap(other)                      — swaps two deques
}
```

---

### Printing a Deque

```cpp
deque<int> dq = {6, 5, 2, 4};

// Range-based for loop (simplest)
for (auto element : dq) {
    cout << element << " ";
}
// Output: 6 5 2 4

// Using iterator
for (auto it = dq.begin(); it != dq.end(); it++) {
    cout << *it << " ";
}
// Output: 6 5 2 4
```

---

### Quick Reference

| Method              | Description                                      |
|---------------------|--------------------------------------------------|
| `push_back(x)`      | Add `x` at the end                               |
| `push_front(x)`     | Add `x` at the beginning                         |
| `emplace_back(x)`   | Construct `x` in-place at the end                |
| `emplace_front(x)`  | Construct `x` in-place at the beginning          |
| `pop_back()`        | Remove last element                              |
| `pop_front()`       | Remove first element                             |
| `front()`           | Access first element                             |
| `back()`            | Access last element                              |
| `dq[i]`             | Random access at index `i` (no bounds check)     |
| `dq.at(i)`          | Random access at index `i` (with bounds check)   |
| `insert(it, x)`     | Insert `x` before iterator position              |
| `erase(it)`         | Remove element at iterator position              |
| `size()`            | Number of elements                               |
| `empty()`           | Returns `true` if deque is empty                 |
| `clear()`           | Remove all elements                              |
| `swap(other)`       | Swap contents with another deque                 |

## 4. Stack

### What is a Stack and Why Do We Need It?

A `stack` is a **LIFO** (Last In, First Out) container adaptor — the last element pushed in is the first one to come out, just like a stack of plates.

```
  push(5) →  ┌───┐  ← top()   pop() removes this first
             │ 5 │
             │ 3 │
             │ 3 │
             │ 2 │
             │ 1 │
             └───┘
```

A `stack` is a **container adaptor** — it is built on top of another container (by default `deque`) and restricts access to only one end (the top). It does **not** expose iterators or random access — you can only see and remove the top element.

---

### How is Stack Different from Vector, List, and Deque?

| Feature                  | `vector`  | `list`    | `deque`   | `stack`         |
|--------------------------|-----------|-----------|-----------|-----------------|
| Access pattern           | Any index | Any node  | Any index | Top only (LIFO) |
| Random access (`[i]`)    | ✅        | ❌        | ✅        | ❌              |
| Insert at front          | ❌ `O(n)` | ✅ `O(1)` | ✅ `O(1)` | ❌ Not allowed  |
| Insert at back           | ✅ `O(1)` | ✅ `O(1)` | ✅ `O(1)` | ✅ via `push()` |
| Iterators                | ✅        | ✅        | ✅        | ❌ None         |
| Use case                 | General   | Frequent middle ops | Both-end ops | Undo, backtracking, recursion |

> 💡 **Use a `stack` when** you need strict LIFO ordering — e.g. undo/redo operations, balancing parentheses, depth-first search (DFS), or function call simulation.

---

### Declaration & Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainStack() {

    stack<int> st;              // Empty stack: {}

    // --- Pushing elements (always added to the top) ---
    st.push(1);                 // {1}         ← top: 1
    st.push(2);                 // {2, 1}      ← top: 2
    st.push(3);                 // {3, 2, 1}   ← top: 3
    st.push(3);                 // {3, 3, 2, 1}← top: 3
    st.emplace(5);              // {5, 3, 3, 2, 1} ← top: 5
    // emplace constructs in-place — slightly faster than push

    // --- Accessing the top ---
    cout << st.top();           // Output: 5  — only the top is visible, nothing below

    // --- Removing the top ---
    st.pop();                   // Removes 5 → {3, 3, 2, 1}
    // ⚠️ pop() does NOT return the value — call top() before pop() if you need it

    cout << st.top();           // Output: 3
    cout << st.size();          // Output: 4

    // --- Empty check ---
    cout << st.empty();         // Output: 0 (false)

    // --- Swapping two stacks ---
    stack<int> st1, st2;
    st1.push(10);
    st1.push(20);               // st1: {20, 10}
    st2.push(99);               // st2: {99}

    st1.swap(st2);              // st1: {99}  |  st2: {20, 10}
}
```

---

### Common Pattern — Read Top Before Popping

Since `pop()` does not return a value, always read the top first:

```cpp
stack<int> st;
st.push(10);
st.push(20);
st.push(30);

// Drain the stack
while (!st.empty()) {
    cout << st.top() << " ";   // Read
    st.pop();                   // Then remove
}
// Output: 30 20 10
```

---

### Quick Reference

| Method        | Description                                          | Returns  |
|---------------|------------------------------------------------------|----------|
| `push(x)`     | Add `x` to the top                                   | `void`   |
| `emplace(x)`  | Construct `x` in-place at the top                    | `void`   |
| `pop()`       | Remove the top element (**does not return it**)       | `void`   |
| `top()`       | Access the top element (no removal)                  | `T&`     |
| `size()`      | Number of elements in the stack                      | `size_t` |
| `empty()`     | Returns `true` if the stack is empty                 | `bool`   |
| `swap(other)` | Swap contents with another stack                     | `void`   |

## 5. Queue

### What is a Queue and Why Do We Need It?

A `queue` is a **FIFO** (First In, First Out) container adaptor — the first element pushed in is the first one to come out, just like a real-world queue (line of people).

```
  push() →  ┌───┬───┬───┐  → pop()
            │ 1 │ 2 │ 9 │
            └───┴───┴───┘
              ↑           ↑
           front()      back()
        (next to leave)  (last to arrive)
```

Like `stack`, a `queue` is a **container adaptor** built on top of `deque` by default. It restricts access to only **two ends** — you can only add at the back and remove from the front. No iterators or random access.

---

### How is Queue Different from Vector, List, Deque, and Stack?

| Feature                   | `vector`  | `list`    | `deque`   | `stack` (LIFO) | `queue` (FIFO)   |
|---------------------------|-----------|-----------|-----------|----------------|------------------|
| Access pattern            | Any index | Any node  | Any index | Top only       | Front & back only|
| Random access (`[i]`)     | ✅        | ❌        | ✅        | ❌             | ❌               |
| Insert at back            | ✅ `O(1)` | ✅ `O(1)` | ✅ `O(1)` | ✅ `O(1)`      | ✅ `O(1)`        |
| Remove from front         | ❌ `O(n)` | ✅ `O(1)` | ✅ `O(1)` | ❌ Not allowed | ✅ `O(1)`        |
| Iterators                 | ✅        | ✅        | ✅        | ❌             | ❌               |
| Order                     | —         | —         | —         | LIFO           | FIFO             |
| Use case                  | General   | Middle ops| Both ends | Undo, DFS      | Scheduling, BFS  |

> 💡 **Use a `queue` when** order of processing matters and you need to handle tasks in the order they arrive — e.g. printer job scheduling, BFS (Breadth-First Search), or CPU task scheduling.

---

### Declaration & Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainQueue() {

    queue<int> q;               // Empty queue: {}

    // --- Pushing elements (always added to the back) ---
    q.push(1);                  // {1}       ← front: 1, back: 1
    q.push(2);                  // {1, 2}    ← front: 1, back: 2
    q.emplace(3);               // {1, 2, 3} ← front: 1, back: 3
    // emplace constructs in-place — slightly faster than push

    // --- Modifying the back element ---
    q.back() += 5;              // {1, 2, 8} ← back (3) becomes 3+5 = 8
    // back() returns a reference, so you can modify it directly

    // --- Accessing elements ---
    cout << q.front();          // Output: 1  — next element to be removed
    cout << q.back();           // Output: 8  — most recently added element
    // ⚠️ No random access — you cannot do q[i] or q.at(i)

    // --- Removing from the front ---
    q.pop();                    // Removes 1 → {2, 8}
    // ⚠️ pop() does NOT return the value — call front() before pop() if you need it

    cout << q.front();          // Output: 2
    cout << q.size();           // Output: 2
    cout << q.empty();          // Output: 0 (false)

    // --- Swapping two queues ---
    queue<int> q1, q2;
    q1.push(10);
    q1.push(20);                // q1: {10, 20}
    q2.push(99);                // q2: {99}

    q1.swap(q2);                // q1: {99}  |  q2: {10, 20}
}
```

---

### Common Pattern — Read Front Before Popping

Since `pop()` does not return a value, always read the front first:

```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

// Drain the queue in FIFO order
while (!q.empty()) {
    cout << q.front() << " ";  // Read
    q.pop();                    // Then remove
}
// Output: 10 20 30
```

> Notice how this is the **opposite of stack** — stack outputs `30 20 10` (LIFO), queue outputs `10 20 30` (FIFO).

---

### Quick Reference

| Method        | Description                                          | Returns  |
|---------------|------------------------------------------------------|----------|
| `push(x)`     | Add `x` to the back                                  | `void`   |
| `emplace(x)`  | Construct `x` in-place at the back                   | `void`   |
| `pop()`       | Remove the front element (**does not return it**)     | `void`   |
| `front()`     | Access the front element (next to be removed)        | `T&`     |
| `back()`      | Access the back element (most recently added)        | `T&`     |
| `size()`      | Number of elements in the queue                      | `size_t` |
| `empty()`     | Returns `true` if the queue is empty                 | `bool`   |
| `swap(other)` | Swap contents with another queue                     | `void`   |

## 6. Priority Queue

### What is a Priority Queue and Why Do We Need It?

A `priority_queue` is a container adaptor where **every element has a priority**, and the element with the **highest priority is always at the top** — ready to be accessed or removed first.

Unlike a regular `queue` (FIFO), a priority queue does **not** care about insertion order — it always serves the most important element first.

Internally, it is implemented as a **binary heap**, which gives it efficient `O(log n)` push and pop operations.

```
  After pushing 5, 1, 8, 10:

  Max-Heap (default):        Min-Heap (greater<int>):

        [10]                         [1]
       /    \                       /   \
     [8]    [5]                   [5]   [8]
     /                            /
   [1]                          [10]

   top() = 10                  top() = 1
   (largest first)             (smallest first)
```

---

### How is Priority Queue Different from Others?

| Feature                  | `queue`      | `stack`      | `priority_queue`              |
|--------------------------|--------------|--------------|-------------------------------|
| Order                    | FIFO         | LIFO         | Priority-based (heap)         |
| Top element              | Oldest item  | Newest item  | Highest (or lowest) priority  |
| Insert                   | `O(1)`       | `O(1)`       | `O(log n)`                    |
| Remove                   | `O(1)`       | `O(1)`       | `O(log n)`                    |
| Random access            | ❌           | ❌           | ❌                            |
| Iterators                | ❌           | ❌           | ❌                            |
| Use case                 | BFS, scheduling | DFS, undo | Dijkstra, task scheduling, top-K problems |

> 💡 **Use a `priority_queue` when** you always need the largest (or smallest) element quickly — e.g. Dijkstra's shortest path, Huffman encoding, scheduling by urgency, or finding the top-K elements.

---

### Max-Heap (Default)

The **largest** element is always at the top.

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainMaxHeap() {

    priority_queue<int> pq;     // Max-heap by default

    pq.push(5);                 // {5}          ← top: 5
    pq.push(1);                 // {5, 1}       ← top: 5
    pq.push(8);                 // {8, 5, 1}    ← top: 8
    pq.emplace(10);             // {10, 8, 5, 1}← top: 10
    // emplace constructs in-place — slightly faster than push

    cout << pq.top();           // Output: 10  — always the largest element

    pq.pop();                   // Removes 10 → {8, 5, 1}

    cout << pq.top();           // Output: 8

    cout << pq.size();          // Output: 3
    cout << pq.empty();         // Output: 0 (false)
}
```

---

### Min-Heap

Pass `greater<int>` as the comparator to flip the order — the **smallest** element is at the top.

```cpp
void explainMinHeap() {

    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap

    pq.push(5);                 // {5}             ← top: 5
    pq.push(1);                 // {1, 5}          ← top: 1
    pq.push(8);                 // {1, 5, 8}       ← top: 1
    pq.emplace(10);             // {1, 5, 8, 10}   ← top: 1

    cout << pq.top();           // Output: 1  — always the smallest element

    pq.pop();                   // Removes 1 → {5, 8, 10}

    cout << pq.top();           // Output: 5
}
```

> ⚠️ The template signature for a min-heap is `priority_queue<Type, Container, Comparator>`:
> - `Type` — the data type (`int`, `pair<int,int>`, etc.)
> - `Container` — always `vector<Type>` here
> - `Comparator` — `greater<Type>` for min-heap, omit (or use `less<Type>`) for max-heap

---

### Common Pattern — Drain in Priority Order

Since `pop()` does not return a value, read `top()` before each pop:

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(4);
pq.push(1);
pq.push(5);

while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
// Output: 5 4 3 1 1  (largest to smallest)
```

---

### Quick Reference

| Method        | Description                                           | Time       | Returns  |
|---------------|-------------------------------------------------------|------------|----------|
| `push(x)`     | Insert `x` into the heap                             | `O(log n)` | `void`   |
| `emplace(x)`  | Construct `x` in-place in the heap                   | `O(log n)` | `void`   |
| `pop()`       | Remove the top element (**does not return it**)       | `O(log n)` | `void`   |
| `top()`       | Access the top element (no removal)                  | `O(1)`     | `const T&`|
| `size()`      | Number of elements                                   | `O(1)`     | `size_t` |
| `empty()`     | Returns `true` if the heap is empty                  | `O(1)`     | `bool`   |

## 7. Set

### What is a Set and Why Do We Need It?

A `set` is an associative container that stores elements in **sorted order** and ensures **all elements are unique** — duplicate insertions are silently ignored.

Internally, a `set` is implemented as a **Red-Black Tree** (a self-balancing BST), which gives it `O(log n)` for insert, find, and erase operations.

```
  After inserting 1, 2, 2, 4, 3:

  Stored as:  { 1, 2, 3, 4 }
               ↑           ↑
            begin()       end()-1

  - Duplicate 2 was ignored
  - 3 was auto-sorted into the correct position
```

---

### How is Set Different from Others?

| Feature               | `vector`      | `unordered_set`  | `set`                  |
|-----------------------|---------------|------------------|------------------------|
| Stores duplicates     | ✅            | ❌               | ❌                     |
| Sorted order          | ❌ (insertion)| ❌ (unordered)   | ✅ Always sorted       |
| Random access (`[i]`) | ✅ `O(1)`     | ❌               | ❌                     |
| Find                  | `O(n)`        | `O(1)` avg       | `O(log n)`             |
| Insert                | `O(1)` amort  | `O(1)` avg       | `O(log n)`             |
| Use case              | General list  | Fast lookup      | Sorted unique elements |

> 💡 **Use a `set` when** you need a collection with **no duplicates** and want elements to always be in **sorted order** — e.g. tracking unique visitors, maintaining a sorted leaderboard, or checking membership efficiently.

---

### Declaration & Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainSet() {

    set<int> st;

    // --- Inserting elements ---
    st.insert(1);               // {1}
    st.emplace(2);              // {1, 2}
    st.insert(2);               // {1, 2}       ← duplicate ignored
    st.insert(4);               // {1, 2, 4}
    st.insert(3);               // {1, 2, 3, 4} ← auto-sorted into correct position

    // --- Iterating (always in sorted order) ---
    for (auto element : st) {
        cout << element << " ";
    }
    // Output: 1 2 3 4

    // --- Finding an element ---
    st.insert(5);               // {1, 2, 3, 4, 5}

    auto it = st.find(3);       // Returns iterator pointing to 3
    cout << *it;                // Output: 3

    auto it2 = st.find(6);      // 6 is not in the set
    if (it2 == st.end()) {
        cout << "Not found";    // Output: Not found
    }
    // ⚠️ Always check against st.end() before dereferencing a find() result

    // --- Counting (useful for membership check) ---
    int cnt = st.count(3);      // Output: 1  — 3 is present
    int cnt2 = st.count(6);     // Output: 0  — 6 is not present
    // In a set, count() only ever returns 0 or 1 (no duplicates exist)

    // --- Erasing by value ---
    set<int> st2 = {1, 2, 3};
    st2.erase(2);               // {1, 3}

    // --- Erasing by iterator range [first, last) ---
    set<int> st3 = {1, 2, 3, 4, 5};
    auto it3 = st3.find(2);     // Points to 2
    auto it4 = st3.find(5);     // Points to 5
    st3.erase(it3, it4);        // Erases [2, 5) → removes 2, 3, 4
                                 // Result: {1, 5}
    // ⚠️ Range erase is [first, last) — last element (5) is NOT removed

    // --- Size & empty check ---
    cout << st.size();          // Output: 5
    cout << st.empty();         // Output: 0 (false)
}
```

---

### Lower Bound & Upper Bound

These are especially powerful with sets since the data is always sorted:

```cpp
set<int> st = {1, 2, 3, 4, 5};

// lower_bound(x) → iterator to first element >= x
auto lb = st.lower_bound(3);
cout << *lb;                    // Output: 3

// upper_bound(x) → iterator to first element > x
auto ub = st.upper_bound(3);
cout << *ub;                    // Output: 4
```

---

### Common Pattern — Check Before Access

```cpp
set<int> st = {1, 2, 3, 4, 5};

// Safe way to find and use an element
auto it = st.find(3);
if (it != st.end()) {
    cout << "Found: " << *it;   // Output: Found: 3
    st.erase(it);               // Erase by iterator — O(1) vs erase by value O(log n)
}
```

> 💡 Erasing by **iterator** is `O(1)`. Erasing by **value** is `O(log n)` because it first has to find the element. If you already have the iterator, prefer `erase(it)`.

---

### Quick Reference

| Method               | Description                                          | Time       | Returns       |
|----------------------|------------------------------------------------------|------------|---------------|
| `insert(x)`          | Insert `x` (ignored if duplicate)                   | `O(log n)` | `pair<it,bool>` |
| `emplace(x)`         | Construct `x` in-place (ignored if duplicate)       | `O(log n)` | `pair<it,bool>` |
| `erase(x)`           | Remove element with value `x`                       | `O(log n)` | `void`        |
| `erase(it)`          | Remove element at iterator position                 | `O(1)`     | `iterator`    |
| `erase(it1, it2)`    | Remove range `[it1, it2)`                           | `O(k log n)` | `iterator`  |
| `find(x)`            | Returns iterator to `x`, or `end()` if not found   | `O(log n)` | `iterator`    |
| `count(x)`           | Returns `1` if `x` exists, `0` otherwise            | `O(log n)` | `int`         |
| `lower_bound(x)`     | Iterator to first element `>= x`                   | `O(log n)` | `iterator`    |
| `upper_bound(x)`     | Iterator to first element `> x`                    | `O(log n)` | `iterator`    |
| `size()`             | Number of elements                                  | `O(1)`     | `size_t`      |
| `empty()`            | Returns `true` if set is empty                      | `O(1)`     | `bool`        |
| `clear()`            | Removes all elements                                | `O(n)`     | `void`        |

## 8. Multiset

### What is a Multiset and Why Do We Need It?

A `multiset` is exactly like a `set` — it stores elements in **sorted order** — but with one key difference: it **allows duplicate values**.

Internally, it is also implemented as a **Red-Black Tree**, giving `O(log n)` for insert, find, and erase.

```
  Insertions: 1, 1, 1, 2, 3

  Stored as:  { 1, 1, 1, 2, 3 }
               ↑              ↑
            begin()        end()-1

  - All three 1s are kept (unlike set which would store just one)
  - Still sorted automatically
```

---

### How is Multiset Different from Set and Others?

| Feature               | `set`              | `multiset`              | `unordered_multiset`     |
|-----------------------|--------------------|-------------------------|--------------------------|
| Duplicates            | ❌ Unique only     | ✅ Allowed              | ✅ Allowed               |
| Sorted order          | ✅                 | ✅                      | ❌                       |
| Find                  | `O(log n)`         | `O(log n)`              | `O(1)` avg               |
| Insert                | `O(log n)`         | `O(log n)`              | `O(1)` avg               |
| `count(x)`            | Returns 0 or 1     | Returns actual count    | Returns actual count     |
| `erase(x)`            | Removes the one copy | Removes **all** copies | Removes **all** copies  |

> 💡 **Use a `multiset` when** you need a sorted collection that **allows duplicates** — e.g. tracking scores where ties are possible, frequency counting with sorted access, or maintaining a sorted list of events.

---

### Declaration & Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainMultiset() {

    multiset<int> ms;

    // --- Inserting elements (duplicates allowed) ---
    ms.insert(1);               // {1}
    ms.insert(1);               // {1, 1}
    ms.insert(1);               // {1, 1, 1}
    ms.insert(2);               // {1, 1, 1, 2}
    ms.insert(3);               // {1, 1, 1, 2, 3}

    // --- count() returns the actual frequency ---
    cout << ms.count(1);        // Output: 3
    cout << ms.count(2);        // Output: 1

    // --- erase(value) removes ALL copies of that value ---
    ms.erase(1);                // Removes all 1s → {2, 3}
    // ⚠️ This is different from set where there's only ever one copy

    // --- Rebuild to demonstrate single deletion ---
    ms.insert(1);               // {1, 2, 3}
    ms.insert(1);               // {1, 1, 2, 3}
    ms.insert(1);               // {1, 1, 1, 2, 3}

    // --- erase(iterator) removes only ONE occurrence ---
    ms.erase(ms.find(1));       // find(1) returns iterator to first 1
                                 // Only that one 1 is erased → {1, 1, 2, 3}
    // ✅ This is the correct way to delete just a single duplicate

    cout << ms.count(1);        // Output: 2  — one 1 was removed, two remain

    // --- find() works the same as set ---
    auto it = ms.find(2);
    if (it != ms.end()) {
        cout << *it;            // Output: 2
    }

    // --- Size & empty check ---
    cout << ms.size();          // Output: 4  ({1, 1, 2, 3})
    cout << ms.empty();         // Output: 0 (false)

    // --- Clear all elements ---
    ms.clear();                 // {}
}
```

---

### The Critical Erase Distinction

This is the most important thing to understand about `multiset`:

```cpp
multiset<int> ms = {1, 1, 1, 2, 3};

// ❌ Erases ALL copies of 1
ms.erase(1);
// Result: {2, 3}

// ✅ Erases only ONE copy of 1
ms.erase(ms.find(1));
// Result: {1, 1, 2, 3}
```

| Erase call          | What it removes               | Time         |
|---------------------|-------------------------------|--------------|
| `erase(value)`      | **All** elements equal to value | `O(log n + k)` where k = count |
| `erase(iterator)`   | **Only one** element at that position | `O(1)`  |
| `erase(it1, it2)`   | All elements in range `[it1, it2)` | `O(k)`  |

---

### Lower Bound & Upper Bound

These work the same as in `set` and are useful for range queries with duplicates:

```cpp
multiset<int> ms = {1, 1, 1, 2, 3};

auto lb = ms.lower_bound(1);    // Iterator to first element >= 1 (first 1)
auto ub = ms.upper_bound(1);    // Iterator to first element >  1 (the 2)

// Erase all 1s using bounds (alternative to erase(value))
ms.erase(lb, ub);               // {2, 3}
```

---

### Quick Reference

| Method               | Description                                              | Time              |
|----------------------|----------------------------------------------------------|-------------------|
| `insert(x)`          | Insert `x` (duplicates allowed)                         | `O(log n)`        |
| `emplace(x)`         | Construct `x` in-place                                  | `O(log n)`        |
| `erase(x)`           | Remove **all** elements equal to `x`                    | `O(log n + k)`    |
| `erase(it)`          | Remove **one** element at iterator position             | `O(1)`            |
| `erase(it1, it2)`    | Remove range `[it1, it2)`                               | `O(k)`            |
| `find(x)`            | Iterator to first occurrence of `x`, or `end()`        | `O(log n)`        |
| `count(x)`           | Number of occurrences of `x`                            | `O(log n + k)`    |
| `lower_bound(x)`     | Iterator to first element `>= x`                       | `O(log n)`        |
| `upper_bound(x)`     | Iterator to first element `> x`                        | `O(log n)`        |
| `size()`             | Total number of elements (counting duplicates)          | `O(1)`            |
| `empty()`            | Returns `true` if multiset is empty                     | `O(1)`            |
| `clear()`            | Removes all elements                                    | `O(n)`            |