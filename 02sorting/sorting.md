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