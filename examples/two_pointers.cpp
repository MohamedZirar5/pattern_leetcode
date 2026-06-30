#include <iostream>
#include <vector>
#include <cassert>

// ============================================================
// Technique 1: Sorted Array - Find Pair with Sum
// ============================================================

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

// ============================================================
// Technique 2: Slow and Fast Pointers - Detect Cycle
// ============================================================

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}

// ============================================================
// Tests
// ============================================================

int main() {
    // Test 1: Sorted array - pair exists
    std::vector<int> arr1 = {1, 3, 5, 7, 9};
    assert(hasPairWithSum(arr1, 12) == true);  // 3 + 9
    std::cout << "Test 1 passed: found pair (3, 9) with sum 12\n";
    
    // Test 2: Sorted array - pair does not exist
    assert(hasPairWithSum(arr1, 2) == false);
    std::cout << "Test 2 passed: no pair found for sum 2\n";
    
    // Test 3: Sorted array - edge case
    std::vector<int> arr2 = {1, 2};
    assert(hasPairWithSum(arr2, 3) == true);  // 1 + 2
    std::cout << "Test 3 passed: found pair (1, 2) with sum 3\n";
    
    // Test 4: Linked list - no cycle
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    assert(hasCycle(head1) == false);
    std::cout << "Test 4 passed: no cycle detected in 1->2->3\n";
    
    // Test 5: Linked list - with cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = head2->next;  // Create cycle: 1->2->3->2
    assert(hasCycle(head2) == true);
    std::cout << "Test 5 passed: cycle detected in 1->2->3->2\n";
    
    std::cout << "\nAll tests passed!\n";
    return 0;
}
