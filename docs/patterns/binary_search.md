# Binary Search

Binary search is the standard pattern for finding an element or the first/last position that satisfies a monotonic condition.

## When it fits

- The input is sorted.
- The answer space is monotonic: once a condition becomes true, it stays true.
- You need the first or last valid index.

## Core idea

Cut the search space in half each step. Keep the invariant that the target, if it exists, is inside the remaining interval.

## Example (C++)

```cpp
#include <vector>

int firstGreaterOrEqual(const std::vector<int>& values, int target) {
    int left = 0;
    int right = (int)values.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (values[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
```

## Complexity

- Time: $O(\log n)$
- Space: $O(1)$

## Mistake to avoid

Use a half-open interval or a closed interval consistently. Mixing both is the fastest way to introduce off-by-one bugs.