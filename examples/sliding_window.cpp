#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

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

int main() {
    std::vector<int> a = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    assert(maxSumSubarray(a, 4) == 39); // 4+2+10+23 = 39
    std::cout << "Sliding window test passed: max sum for k=4 is 39\n";
    return 0;
}
