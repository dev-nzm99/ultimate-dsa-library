# Two Pointers: Expanding From Center (Palindromes)

## 1. Pattern Overview

Imagine you’re reading a word and want to check if it’s a palindrome—like “level” or “racecar.” You might start from the middle and check if the letters on both sides match as you move outward. This is exactly what the **Expanding From Center** subpattern of the Two Pointers technique does!

Think of it like standing in the middle of a bridge and taking steps outward in both directions, checking if the scenery on your left and right is the same at each step. If you keep seeing the same thing on both sides, you know you’re on a symmetrical bridge—a palindrome!

This pattern is especially useful for problems involving **palindromic substrings** in strings. Instead of checking every possible substring (which can be slow), we use the insight that every palindrome is centered around a point (or between two points for even-length palindromes). By expanding outwards from each possible center, we efficiently find all palindromic substrings or the longest one.

When is this pattern useful?

* When you need to find palindromic substrings or the longest palindrome in a string.
* When the problem involves checking for symmetry within a sequence.
* When brute-force approaches would be too slow due to overlapping subproblems.

Everyday analogy: Think about folding a piece of paper in half. If both sides line up perfectly, the fold is at the center of symmetry. Similarly, palindromes have a “fold” (center) where both halves mirror each other.

---

## 2. Core Concepts

### What is a Palindrome?

A palindrome is a sequence that reads the same backward and forward. For example, “madam” or “abba”.

### Why Expand From the Center?

* **Observation:** Every palindrome has a center. For odd-length palindromes (like “racecar”), the center is a single character. For even-length palindromes (like “abba”), the center is between two characters.
* **Efficiency:** Instead of checking all possible substrings (O(n³)), expand from each possible center (O(n²)).

### Visualizing the Process

Imagine a string as a row of tiles. Place two fingers at the center(s) and move them outward, comparing the tiles under each finger. Each successful expansion marks a palindrome.

### Time and Space Complexity

* **Time:** O(n²) — 2n-1 possible centers, expand up to n/2 each.
* **Space:** O(1) extra space, unless storing all substrings.

### Mathematical Foundation

* Symmetry means checking characters equidistant from the center is sufficient.
* Dynamic Programming can also be used, but Expanding From Center is intuitive and space-efficient.

---

## 3. Implementation Approach

### Step-by-Step Thinking

**1. Identify All Possible Centers**

* For a string of length n, n single-character centers (odd-length) and n-1 pairs of adjacent characters (even-length).

**2. Expand Outward From Each Center**

* Use two pointers: `left` and `right`.
* While characters at `left` and `right` match and within bounds, expand outward.
* Think: “As long as both sides match, the substring is a palindrome.”

**3. Track Results**

* Counting palindromic substrings: increment a counter each time you find one.
* Finding the longest palindrome: track maximum length and starting index.

**4. Handle Edge Cases**

* Single-character strings are always palindromes.
* Empty strings have zero palindromic substrings.
* Repeated characters (like “aaaa”) have overlapping palindromes.

**5. Decision Tree**

* Problem asks for palindromic substrings or longest palindrome?
* Input is a string?
* Brute-force too slow?

**Example:** “abba”

* Centers: ‘a’, ‘b’, ‘b’, ‘a’, and between each pair.
* Expanding from center between two ‘b’s yields “bb” then “abba”.

**Practical Tips**

* Use helper functions for odd/even centers.
* Check string boundaries carefully to avoid out-of-bounds errors.

---

## 🧩 PRACTICE PROBLEMS

1. **Longest Palindromic Substring**

   * [LeetCode Link](https://leetcode.com/problems/longest-palindromic-substring/)

2. **Palindromic Substrings**

   * [LeetCode Link](https://leetcode.com/problems/palindromic-substrings/)

3. **Count Substrings That Are Palindromes**

   * [LeetCode Link](https://leetcode.com/problems/count-substrings-that-are-palindromes/)

By practicing these problems, you'll master the **Expanding From Center** pattern and efficiently solve palindrome substring challenges using two pointers.
