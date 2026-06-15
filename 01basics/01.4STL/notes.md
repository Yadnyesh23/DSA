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

### What is a Vector and why do we need it?

A `vector` is a **dynamic array** — unlike a plain array, it can grow and shrink in size automatically at runtime. It stores elements in contiguous memory, making random access fast (`O(1)`).

```cpp
#include <bits/stdc++.h>
using namespace std;

void explainVector() {

    // --- Declaration ---
    vector<int> v;              // Empty vector:       {}
    v.push_back(1);             // Append 1:           {1}
    v.push_back(2);             // Append 2:           {1, 2}
    v.emplace_back(3);          // Append 3:           {1, 2, 3}
    // emplace_back is faster than push_back because it constructs
    // the element in-place, avoiding an extra copy/move operation.

    // --- Vector of pairs ---
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});      // Requires explicit braces:  {1, 2}
    vec.emplace_back(1, 2);     // Constructs pair in-place — no braces needed

    // --- Initialisation shortcuts ---
    vector<int> a(5, 100);      // 5 elements, all 100:  {100, 100, 100, 100, 100}
    vector<int> b(5);           // 5 elements, all 0:    {0, 0, 0, 0, 0}

    vector<int> v1(5, 20);      // {20, 20, 20, 20, 20}
    vector<int> v2(v1);         // Copy of v1:  {20, 20, 20, 20, 20}
}
```

---

### Accessing Elements

**Method 1 — Index-based access**

```cpp
vector<int> v = {10, 20, 30, 40, 50};

cout << v[3];      // Output: 40  (0-indexed, no bounds check)
cout << v.at(3);   // Output: 40  (0-indexed, throws exception if out of range)
```

> ⚠️ `v[3]` and `v.at(3)` both access the **4th element** (index 3). `v.at()` is safer as it does bounds checking.

---

**Method 2 — Iterators**

An iterator is like a pointer that points to an element inside a container.

```
Vector:   {10,  20,  30,  40,  50}
           ↑                    ↑   ↑
         begin()             back() end()  ← points ONE past the last element

Reverse:  {10,  20,  30,  40,  50}
        ↑   ↑
     rend() rbegin()  ← points at last element (50)
```

```cpp
vector<int> v = {10, 20, 30, 40, 50};

vector<int>::iterator it = v.begin();  // Points to first element (10)
cout << *it;                           // Output: 10
it++;
cout << *it;                           // Output: 20

v.end();    // Points ONE place past the last element (past 50) — do NOT dereference
v.rbegin(); // Reverse begin — points at last element (50)
v.rend();   // Reverse end — points one place before first element (before 10)

cout << v.back();  // Output: 50  (last element)
cout << v.front(); // Output: 10  (first element)
```

---

### Printing a Vector

**Using an explicit iterator:**
```cpp
for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
// Output: 10 20 30 40 50
```

**Using `auto` (cleaner, preferred):**
```cpp
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
// Output: 10 20 30 40 50
```

**Using range-based for loop (simplest):**
```cpp
for (auto element : v) {
    cout << element << " ";
}
// Output: 10 20 30 40 50
```