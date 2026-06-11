# Recursion

---

## What is Recursion?

Recursion is when a **function calls itself** repeatedly until a specified condition (called the **base condition**) is met.

Every recursive function has two parts:
1. **Base Condition** — the condition where the function *stops* calling itself (prevents infinite recursion)
2. **Recursive Call** — the part where the function calls itself with a modified input, moving toward the base condition

```cpp
void countdown(int n) {
    if (n == 0) {       // base condition
        cout << "Done!";
        return;
    }
    cout << n << " ";
    countdown(n - 1);   // recursive call
}
```

Output for `countdown(3)`: `3 2 1 Done!`

---

## Stack Space

When a function is called, it gets pushed onto the **call stack** — a region of memory that keeps track of active function calls.

> **The call stack stores all functions that have been called but not yet finished.**

Each function call holds:
- Its local variables
- Its parameters
- The return address (where to go back after it finishes)

### Example — How the Stack Builds Up

```cpp
void fun(int n) {
    if (n == 0) return;   // base condition
    cout << n << " ";
    fun(n - 1);
    cout << n << " ";     // runs AFTER the recursive call returns
}
```

Call: `fun(3)`

**Stack builds up (push):**
```
fun(3) → prints 3, calls fun(2)
  fun(2) → prints 2, calls fun(1)
    fun(1) → prints 1, calls fun(0)
      fun(0) → base condition, returns
```

**Stack unwinds (pop):**
```
fun(1) resumes → prints 1
fun(2) resumes → prints 2
fun(3) resumes → prints 3
```

Output: `3 2 1 1 2 3`

---

## Base Condition

The base condition is the **termination condition** — the point at which the function stops making recursive calls and starts returning.

> Without a base condition, the function calls itself forever → **Stack Overflow**.

```cpp
// ❌ No base condition — infinite recursion
void infinite(int n) {
    cout << n;
    infinite(n - 1);
}

// ✅ With base condition
void finite(int n) {
    if (n == 0) return;   // base condition
    cout << n;
    finite(n - 1);
}
```

---

## Stack Overflow

**Stack Overflow** occurs when the call stack runs out of memory.

This happens when:
- There is **no base condition** (infinite recursion)
- The base condition is **never reached** (e.g., wrong logic)
- The recursion is **too deep** (n is extremely large)

```cpp
// Causes stack overflow if n is huge or base condition is wrong
void fun(int n) {
    if (n == 0) return;
    fun(n + 1);   // ❌ n increases, never reaches 0
}
```

Each function call takes stack space. When the stack fills up completely, the OS throws a **Stack Overflow error** and the program crashes.

> Stack memory is limited (typically 1–8 MB). Deep recursion with large `n` can exhaust it quickly.

---

## Recursion Tree

A **recursion tree** is a visual representation of all the recursive calls made by a function. It helps in understanding the flow and calculating time complexity.

### Example — `fun(4)` where each call spawns two calls

```cpp
int fun(int n) {
    if (n <= 0) return 0;
    return fun(n - 1) + fun(n - 1);
}
```

```
                  fun(4)
               /          \
          fun(3)           fun(3)
         /     \           /     \
      fun(2)  fun(2)   fun(2)  fun(2)
      / \      / \      / \      / \
    f(1) f(1) f(1) f(1) f(1) f(1) f(1) f(1)
```

- Each level doubles the number of calls
- Total calls = `2⁰ + 2¹ + 2² + 2³ + 2⁴` = `2ⁿ⁺¹ - 1` ≈ **O(2ⁿ)** time
- Maximum depth = `n` → **O(n)** space (call stack)

### Example — Fibonacci

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

```
              fib(4)
            /        \
        fib(3)        fib(2)
       /     \        /    \
   fib(2)  fib(1)  fib(1) fib(0)
   /    \
fib(1) fib(0)
```

- TC = **O(2ⁿ)** — many repeated subproblems (fixable with memoisation)
- SC = **O(n)** — maximum depth of the call stack

---

## Types of Recursion

| Type | Description | Example |
|------|-------------|---------|
| **Direct** | Function calls itself | `fun()` calls `fun()` |
| **Indirect** | Function A calls B, B calls A | `f()` → `g()` → `f()` |
| **Tail** | Recursive call is the **last** operation | `fun(n-1)` after no more work |
| **Head** | Recursive call is the **first** operation | Call happens before any processing |
| **Tree** | Each call makes **multiple** recursive calls | Fibonacci, binary tree traversal |

### Tail Recursion (important for optimisation)

```cpp
// NOT tail recursive — multiplication happens after the call returns
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);   // work done on return
}

// Tail recursive — accumulator carries the result
int factorial(int n, int acc = 1) {
    if (n == 0) return acc;
    return factorial(n - 1, n * acc);   // no pending work
}
```

Tail recursion can be optimised by compilers into a loop (**Tail Call Optimisation**), avoiding stack overflow for large inputs.

---

## Time & Space Complexity of Recursion

| Function | TC | SC |
|----------|----|----|
| Linear recursion (`fun(n-1)`) | O(n) | O(n) |
| Binary recursion (`fun(n-1) + fun(n-1)`) | O(2ⁿ) | O(n) |
| Divide & conquer (`fun(n/2)`) | O(log n) | O(log n) |
| Merge sort | O(n log n) | O(n) |

> Space complexity of recursion is determined by the **maximum depth of the call stack**, not the total number of calls.

---

## Recursion vs Iteration

| | Recursion | Iteration |
|---|-----------|-----------|
| **Code clarity** | Often simpler and elegant | Can be verbose |
| **Stack usage** | Uses call stack (risk of overflow) | No extra stack (O(1) space usually) |
| **Speed** | Slightly slower (function call overhead) | Generally faster |
| **Use case** | Trees, graphs, divide & conquer | Simple loops, counters |

> Rule of thumb: use recursion when the problem is **naturally recursive** (trees, graphs, backtracking). Convert to iteration if stack depth is a concern.

---

*Notes by Yadnyesh*