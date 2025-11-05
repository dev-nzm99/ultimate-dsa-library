/*
 C++ example based on the "Maximum Average Subarray I" problem.
*/
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

// Function to find the maximum average of any subarray of length k
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0.0; // Edge case: not enough elements

    // Calculate the sum of the first window of size k
    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }
    int maxSum = windowSum; // Initialize maxSum with the first window's sum

    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        // Subtract the element leaving the window and add the new element
        windowSum = windowSum - nums[i - k] + nums[i];
        // Update maxSum if we found a larger sum
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    // The maximum average is maxSum divided by window size k
    return static_cast<double>(maxSum) / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = findMaxAverage(nums, k);
    cout << "Maximum average of any subarray of length " << k << " is: " << result << endl;
    // Output: Maximum average of any subarray of length 4 is: 12.75
    return 0;
}
