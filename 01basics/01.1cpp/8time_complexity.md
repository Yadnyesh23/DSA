# Time Complexity and Space Complexity

---

## Time Complexity

**Time complexity ≠ Time taken by code to run**

The time a program takes to run depends on the hardware, OS, and system configuration — so it's not a reliable measure. Instead:

> **Time Complexity** = The rate at which the time taken increases *relative to the input size*.

Time Complexity is expressed using **Big-O notation**, and is **always computed for the worst-case scenario**.

### Rules of Thumb

- **Ignore constants** — `O(3n)` → `O(n)`
- **Ignore lower-order terms** — `O(4n³ + 3n² + 8)` → `O(n³)`

**Why?** As `n → ∞`, lower-order terms become negligible.  
Example: if `n = 10⁵`, then `4n³ = 4 × 10¹⁵` vs `3n² = 3 × 10¹⁰` — adding `10¹⁰` to `10¹⁵` barely matters.

---

### Cases in Time Complexity

| Case | Meaning | Notation |
|------|---------|----------|
| Best Case | Minimum operations (most favourable input) | Ω (Omega) |
| Average Case | Expected operations for typical input | Θ (Theta) |
| Worst Case | Maximum operations (least favourable input) | O (Big-Oh) |

---

### Notation Summary

| Notation | Name | Represents |
|----------|------|------------|
| O (Big-Oh) | Upper Bound | Worst Case |
| Ω (Omega) | Lower Bound | Best Case |
| Θ (Theta) | Tight Bound | Average Case |

> In competitive programming and interviews, **Big-O (worst case)** is almost always what's asked for.

---

### Example 1 — Simple Loop

```cpp
for (int i = 1; i <= n; i++) {
    cout << "Hello";
}
```

Each iteration does ~3 operations: check `i <= n`, print, increment `i`.  
Total: `O(3n)` → drop constant → **O(n)**

---

### Example 2 — Conditional Chains (Grade Example)

```cpp
if (marks < 25) {
    cout << "Grade D";
} else if (marks < 45) {
    cout << "Grade C";
} else if (marks < 65) {
    cout << "Grade B";
} else {
    cout << "Grade A";
}
```

- `marks = 23`: hits first condition → **O(1)** (Best Case)
- `marks = 75`: checks all 3 conditions, hits `else` → **O(4)** → **O(1)** (Worst Case, still constant)

Since the number of checks doesn't depend on `n`, this is **O(1)** overall.

---

### Practice Questions

#### Q1 — Nested Loops (Equal Range)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) work
    }
}
```

```
i=0 → j runs n times
i=1 → j runs n times
...
i=n-1 → j runs n times
```

Total = `n × n` → **TC = O(n²)**

---

#### Q2 — Nested Loops (Triangular Pattern)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        // O(1) work
    }
}
```

```
i=0 → j runs 1 time
i=1 → j runs 2 times
i=2 → j runs 3 times
...
i=n-1 → j runs n times
```

Total = `1 + 2 + 3 + ... + n` = `n(n+1)/2`  
Drop constants → **TC = O(n²)**

---

#### Q3 — Logarithmic Loop

```cpp
for (int i = 1; i < n; i = i * 2) {
    // O(1) work
}
```

`i` doubles each time: `1, 2, 4, 8, ..., n`  
Runs for `log₂(n)` iterations → **TC = O(log n)**

Similarly:
```cpp
for (int i = n; i >= 1; i = i / 2) { ... }  // O(log n)
```

---

#### Q4 — Mixed (Loop + Log)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j = j * 2) {
        // O(1) work
    }
}
```

Outer loop: `O(n)`, Inner loop: `O(log n)` → **TC = O(n log n)**

---

### Common Time Complexities (Best → Worst)

| Complexity | Name | Example |
|------------|------|---------|
| O(1) | Constant | Array index access |
| O(log n) | Logarithmic | Binary search |
| O(√n) | Square root | Sieve of Eratosthenes |
| O(n) | Linear | Simple loop |
| O(n log n) | Linearithmic | Merge sort, Heap sort |
| O(n²) | Quadratic | Bubble sort, nested loops |
| O(n³) | Cubic | Triple nested loops |
| O(2ⁿ) | Exponential | Recursive Fibonacci |
| O(n!) | Factorial | Generating all permutations |

> **Rule of thumb for competitive programming:**  
> A typical online judge allows ~10⁸ operations per second.  
> - 1 sec time limit ≈ `10⁸` operations  
> - 2 sec time limit ≈ `2 × 10⁸` operations

---

## Space Complexity

> **Space Complexity** = Total memory used by a program relative to the input size.

```
Space Complexity = Auxiliary Space + Input Space
```

| Term | Meaning |
|------|---------|
| **Input Space** | Memory used to store the input itself |
| **Auxiliary Space** | Extra memory used by the algorithm to solve the problem (temporary variables, stacks, etc.) |

> When comparing algorithms, **Auxiliary Space** is usually more meaningful, since input is unavoidable.

---

### Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 2;   // input
    int b = 3;   // input
    int c = a + b;  // auxiliary variable
    cout << c;
}
```

- `a`, `b` → Input Space
- `c` → Auxiliary Space
- Total SC = **O(1)** (no arrays, no recursion)

---

### ⚠️ Do NOT Manipulate Input to Save Space

```cpp
// Bad practice — modifies input
int b = a + b;
cout << b;
```

While this saves one variable, it **destroys the original input**, which can cause bugs and is considered bad practice. Always preserve inputs.

---

### Space in Recursive Calls

Each recursive call adds a **stack frame** to the call stack. For example:

```cpp
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

This creates `n` stack frames before unwinding → **Space Complexity = O(n)**

---

### Common Space Complexities

| Complexity | Example |
|------------|---------|
| O(1) | Swapping two variables |
| O(n) | Storing an array of size n |
| O(n²) | 2D matrix of size n×n |
| O(log n) | Binary search (recursive, due to call stack) |
| O(n) | DFS on a graph with n nodes (call stack) |

---

### Space–Time Tradeoff

Often you can trade space for time (or vice versa). For example:
- **Memoization** uses extra O(n) space to reduce time from O(2ⁿ) to O(n).
- **In-place sorting** saves space but may increase time or code complexity.

> Choose based on the problem's constraints — if memory is limited, optimise space; if time is critical, use caching/memoisation.

---

*Notes by Yadnyesh*