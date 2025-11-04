/*
 AUthor:Nazmul Islam
 Created: 2025-11-04 08:34
*/
// Find indices of two numbers in a sorted array that add up to a target
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSumSorted(const vector<int>& nums, int target) {
    int left = 0;                      // Start pointer at the beginning
    int right = nums.size() - 1;       // End pointer at the end

    while (left < right) {
        int sum = nums[left] + nums[right]; // Current sum of two pointers

        if (sum == target) {
            // Found the pair! Return their indices
            return {left, right};
        } else if (sum < target) {
            // Need a larger sum, move left pointer right
            left++;
        } else {
            // Need a smaller sum, move right pointer left
            right--;
        }
    }
    // No pair found
    return {};
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6};
    int target = 6;
    vector<int> result = twoSumSorted(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }
    return 0;
}
