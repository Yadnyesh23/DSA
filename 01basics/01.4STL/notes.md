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
