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