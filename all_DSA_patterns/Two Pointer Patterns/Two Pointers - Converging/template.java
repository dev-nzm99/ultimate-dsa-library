/*
  Author:Nazmul Islam
  Created: 2025-11-05 10:34
*/
// Find indices of two numbers in a sorted array that add up to a target
import java.util.ArrayList;
import java.util.List;

public class TwoPointersConverging {

    /**
     * Finds indices of two numbers in a sorted array that add up to the target.
     * Uses the two pointers (converging) technique.
     *
     * @param nums   Sorted list of integers
     * @param target Target sum to find
     * @return List containing the indices of the two numbers, or empty list if not found
     */
    public static List<Integer> twoSumSorted(List<Integer> nums, int target) {
        int left = 0;                          // Start pointer at the beginning
        int right = nums.size() - 1;           // End pointer at the end

        while (left < right) {
            int sum = nums.get(left) + nums.get(right); // Current sum of two pointers

            if (sum == target) {
                // Found the pair! Return their indices
                List<Integer> result = new ArrayList<>();
                result.add(left);
                result.add(right);
                return result;
            } else if (sum < target) {
                // Need a larger sum, move left pointer right
                left++;
            } else {
                // Need a smaller sum, move right pointer left
                right--;
            }
        }
        // No pair found
        return new ArrayList<>();
    }

    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);
        nums.add(4);
        nums.add(6);

        int target = 6;
        List<Integer> result = twoSumSorted(nums, target);

        if (!result.isEmpty()) {
            System.out.println("Indices: " + result.get(0) + ", " + result.get(1));
        } else {
            System.out.println("No pair found.");
        }
    }
}
