# Two Pointers

Use two pointers when a problem can be reduced to a coordinated scan from one or two ends of a sequence.

## When it fits

- The input is sorted or can be sorted without breaking the goal.
- You want to compare mirrored positions or keep a left/right boundary moving toward each other.
- A brute-force pair check is too slow.

## Core idea

Move one pointer based on the current state of the other. The key is that every move should eliminate a group of impossible candidates.

## Example

```cpp
#include <vector>

bool hasPairWithSum(const std::vector<int>& values, int target) {
    int left = 0;
    int right = values.size() - 1;

    while (left < right) {
        int current_sum = values[left] + values[right];
        if (current_sum == target) {
            return true;
        }
        if (current_sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}
```

## Complexity

- Time: $O(n)$
- Space: $O(1)$

## Mistake to avoid

Do not move both pointers blindly. Each move should be justified by the comparison result. Moving the wrong pointer defeats the invariant.
