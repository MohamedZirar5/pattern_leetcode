# Digit Dynamic Programming (Digit DP)

Digit DP is a technique for counting or optimizing over numbers by processing them digit-by-digit while remembering tightness to an upper bound and other state (like sum, parity, or whether a forbidden digit appeared).

## When it fits

- You need to count or find properties of numbers in a range [0..N] (or between A and B).
- The property depends on digits (sum of digits, contains/avoids certain digits, digit order constraints, etc.).
- A range query between `A` and `B` is usually solved as `count(B) - count(A - 1)`.

## Core idea

Represent the upper bound `N` as a digit array. Build a recursive DP processing digits from most-significant to least-significant while tracking:

- `pos`: current digit index
- `tight`: whether the prefix equals the prefix of `N` (restricting the next digit)
- `leading_zero`: whether we've seen any non-zero digits yet (affects some properties)
- additional problem-specific state (e.g., current sum modulo k, whether we have seen a forbidden pattern)

The `leading_zero` flag is the difference between counting the number `0` correctly and accidentally treating shorter numbers as if they had the same digit length as `N`.

Transition by trying all allowed digits 0..limit where `limit` is `9` or the digit from `N` depending on `tight`.

## Example (C++)

Problem: Count numbers in `[0..N]` that do NOT contain the digit `4`.

The example implements a memoized digit-DP and demonstrates correctness on small test cases.

```cpp
#include <bits/stdc++.h>
using namespace std;

long long dfs(const vector<int>& digs, int pos, bool tight, bool leading, vector<vector<vector<long long>>>& memo) {
    if (pos == (int)digs.size()) return 1; // reached end: one valid number
    long long &out = memo[pos][tight][leading];
    if (out != -1) return out;
    out = 0;
    int limit = tight ? digs[pos] : 9;
    for (int d = 0; d <= limit; ++d) {
        if (d == 4) continue; // forbidden digit
        bool ntight = tight && (d == limit);
        bool nleading = leading && (d == 0);
        out += dfs(digs, pos + 1, ntight, nleading, memo);
    }
    return out;
}

long long countWithout4(long long N) {
    if (N < 0) return 0;
    string s = to_string(N);
    vector<int> digs;
    for (char c: s) digs.push_back(c - '0');
    int n = digs.size();
    vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(2, vector<long long>(2, -1)));
    return dfs(digs, 0, true, true, memo);
}

int main() {
    // Tests
    // 0..9: exclude 4 -> 9 numbers (0..9 inclusive are 10 numbers; remove 4)
    assert(countWithout4(9) == 9);
    // 0..20: exclude 4 and 14 -> 21 total numbers - 2 = 19
    assert(countWithout4(20) == 19);
    // 0..99: two-digit positions with each digit excluding 4 -> 9*9 = 81
    assert(countWithout4(99) == 81);
    // 0..100: same as 0..99 plus 100 (which doesn't contain 4) -> 82
    assert(countWithout4(100) == 82);
    cout << "Digit DP tests passed." << endl;
    return 0;
}
```

## Complexity

- Time: $O(d \times states)$ where $d$ is number of digits and `states` derives from tight/other state; typically linear in digits times small constant factors.
- Space: $O(d \times states)$ for memoization.

## Pitfalls

- Carefully handle leading zeros (they often affect state transitions).
- Include `tight` in memoization key only when appropriate (tight==true states are usually not reusable across different prefixes).
- Validate on small values to ensure base cases are correct.