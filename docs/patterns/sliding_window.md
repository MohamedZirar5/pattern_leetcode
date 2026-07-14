# Sliding Window

Sliding window is useful when the answer depends on a contiguous segment and you want to update that segment incrementally.

## When it fits

- You are tracking counts, totals, or a validity condition over a subarray or substring.
- The optimal solution grows and shrinks a window instead of restarting from scratch.
- The window may have a fixed size or a variable size that you adjust until it becomes valid again.

## Core idea

Expand the right side to include new information. Shrink the left side when the window becomes invalid or too large.
For fixed-size windows, you usually add the new right value and remove the value that just left the window in the same step.

## Example (C++)

```cpp
#include <vector>

int maxSumSubarray(const std::vector<int>& values, int k) {
    if (k <= 0 || k > (int)values.size()) throw std::invalid_argument("k out of range");
    int window_sum = 0;
    for (int i = 0; i < k; ++i) window_sum += values[i];
    int best = window_sum;
    for (int right = k; right < (int)values.size(); ++right) {
        window_sum += values[right];
        window_sum -= values[right - k];
        if (window_sum > best) best = window_sum;
    }
    return best;
}
```

## Complexity

- Time: $O(n)$
- Space: $O(1)$

## Mistake to avoid

For variable-size windows, ensure you update the state consistently when expanding and shrinking the window. For fixed-size windows, make sure the initial window is valid before you start sliding it.