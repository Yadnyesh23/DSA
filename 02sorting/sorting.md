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
