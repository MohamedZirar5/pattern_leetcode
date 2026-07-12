#include <cassert>
#include <iostream>
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

int main() {
    std::vector<int> values = {1, 3, 3, 5, 8, 13};
    assert(firstGreaterOrEqual(values, 0) == 0);
    assert(firstGreaterOrEqual(values, 3) == 1);
    assert(firstGreaterOrEqual(values, 4) == 3);
    assert(firstGreaterOrEqual(values, 14) == 6);
    std::cout << "Binary search tests passed.\n";
    return 0;
}
