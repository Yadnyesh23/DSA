# What is Sorting

Sorting is the process of arranging elements in a specific order (ascending or descending) within a data structure.

---

## Types of Sorting Techniques

### 1. Selection Sort

The array is conceptually divided into two parts: a **sorted** portion and an **unsorted** portion.

**How it works:**
- Assume the first element is sorted; everything else is unsorted.
- Find the **smallest element** in the unsorted portion.
- **Swap** it with the first element of the unsorted portion.
- Repeat until the entire array is sorted.

**Time Complexity:**

| Case    | Complexity |
|---------|------------|
| Best    | O(n²)      |
| Average | O(n²)      |
| Worst   | O(n²)      |

**Why O(n²)?**
For each of the `n` elements, we scan the remaining unsorted portion — which itself takes up to `n` comparisons. This gives us `n × n = n²` operations in all cases, making it inefficient for large datasets.

### 2. Bubble Sort

In Bubble Sort, swapping is done only between adjacent elements.

**How it works:**
- Compare each pair of adjacent elements.
- If the left element is greater than the right element, swap them.
- Continue this process until the largest element "bubbles" to the end of the array.
- Repeat for the remaining unsorted portion until the entire array is sorted.

**Time Complexity:**

| Case | Without Optimization | With Optimization |
|------|----------------------|-------------------|
| Best | O(n²) | O(n) |
| Average | O(n²) | O(n²) |
| Worst | O(n²) | O(n²) |

**Why O(n²)?**
Bubble Sort performs multiple passes over the array. In each pass, adjacent elements are compared and swapped if they are in the wrong order. In the worst and average cases, it performs approximately `(n - 1) + (n - 2) + ... + 1` comparisons, which equals `n(n - 1)/2`. Ignoring constants, this becomes **O(n²)**.

**Space Complexity:** O(1)

**Stable:** Yes

**In-place:** Yes

### 3. Insertion Sort

Insertion Sort builds the sorted array one element at a time by repeatedly inserting the next unsorted element into its correct position in the already-sorted portion.

**How it works:**
- Assume the first element is already sorted.
- Take the next element (key) from the unsorted portion.
- Compare it with elements in the sorted portion (moving from right to left).
- Shift elements that are greater than the key one position to the right.
- Insert the key into its correct position.
- Repeat until all elements are processed.

**Time Complexity:**

| Case      | Without Optimization | With Optimization |
|-----------|----------------------|-------------------|
| Best      | O(n)                 | O(n)              |
| Average   | O(n²)                | O(n²)             |
| Worst     | O(n²)                | O(n²)             |

**Why O(n²)?**  
In the worst and average cases, each new element may need to be compared with and shifted past all previously sorted elements. This leads to roughly `1 + 2 + ... + (n - 1) = n(n - 1)/2` comparisons/shifts, which simplifies to **O(n²)**.  
In the best case (already sorted array), each element is compared once and no shifts are needed, giving **O(n)**.

**Space Complexity:** O(1)

**Stable:** Yes

**In-place:** Yes

### 4. Merge Sort

Merge Sort is a divide-and-conquer sorting algorithm. It repeatedly divides the array into smaller subarrays until each subarray contains only one element, and then merges those subarrays back together in sorted order.

**How it works:**
- Start with the entire array.
- Find the middle index of the current subarray.
- Divide the array into two halves:
  - Left half: `low` to `mid`
  - Right half: `mid + 1` to `high`
- Recursively divide both halves.
- Continue dividing until `low == high`, meaning only one element remains.
- Start merging the smaller subarrays.
  - During merging, compare the first unprocessed element of both sorted halves.
  - Place the smaller element into a temporary array.
  - Continue until all elements from both halves have been processed.
- Copy the merged elements back into the original array.
- Continue merging larger sorted subarrays until the entire array is sorted.

**Example:**

```text
[1][2][3][4][5]

        Divide
           ↓
[1][2][3][4][5]

      ↓             ↓

[2][5]

   ↓                ↓

             

        Merge
           ↓

[1][2][4][5]

           ↓

[1][2][3][4][5]

           ↓

[2][3][4][5][1]
```

**Time Complexity:**

| Case    | Complexity     |
|---------|----------------|
| Best    | O(n log n)     |
| Average | O(n log n)     |
| Worst   | O(n log n)     |

**Why O(n log n)?**  
- The array is divided into halves repeatedly, resulting in approximately `log n` levels of division.  
- At every level, all `n` elements are processed during merging.  
- Therefore: `n × log n = O(n log n)`.

**Space Complexity:** O(n)  
A temporary array is used during the merging process to store the sorted elements.

**Stable:** Yes

**In-place:** No

**Key Idea:**  
Divide the array until single elements remain, then merge the elements back in sorted order.

**Remember:**

```text
Divide → Divide → Divide
                    ↓
Merge → Merge → Merge
                    ↓
             Sorted Array
```

### 5. Recursive Bubble Sort

Recursive Bubble Sort is a recursive version of the **Bubble Sort** algorithm. Instead of using an outer loop to perform multiple passes, it uses **recursion** to repeat the sorting process for the remaining unsorted portion of the array.

**How it works:**

1. Start with the entire array.
2. Perform one complete Bubble Sort pass over the unsorted portion:
   - Compare adjacent elements.
   - If the left element is greater than the right element, swap them.
3. After one complete pass, the largest element moves to the end of the unsorted portion.
4. Reduce the size of the unsorted portion by one.
5. Recursively call the function for the remaining unsorted portion.
6. Stop when only one element remains, because a single element is already sorted.

**Example:**

```text
[1][2][3][4][5]

        ↓ One pass

[1][2][3][4][5]
             ↑
        Largest fixed

        ↓ Recursive call

[1][2][3][4]

        ↓ One pass

[1][2][3][4]
          ↑
      Largest fixed

        ↓ Recursive call

[1][2][3]

        ↓ One pass

[2][3][1]

        ↓

[1][2][3][4][5]
```

**Base Case:**  
The recursion stops when only one element remains:

```text
n == 1
```

A single element is already sorted, so no further work is required.

**Time Complexity:**

| Case    | Complexity |
|---------|------------|
| Best    | O(n)       |
| Average | O(n²)      |
| Worst   | O(n²)      |

**Why O(n²)?**  
- Each recursive call performs a Bubble Sort pass over the remaining unsorted portion.  
- The number of comparisons is approximately:  
  \[
  (n - 1) + (n - 2) + \dots + 1 = \frac{n(n - 1)}{2}
  \]  
- Therefore, the average and worst-case time complexity is **O(n²)**.  
- With the no-swap optimization, the best case becomes **O(n)** because the algorithm can stop early when the array is already sorted.

**Space Complexity:** O(n)  
The algorithm uses O(n) space because of the recursive call stack.

**Stable:** Yes

**In-place:** Yes

**Key Idea:**  
Perform one Bubble Sort pass, fix the largest element at the end, reduce the unsorted portion, and recursively repeat.

**Remember:**

```text
One Pass
   ↓
Largest Element Fixed
   ↓
Reduce n
   ↓
Recursive Call
   ↓
Repeat
```