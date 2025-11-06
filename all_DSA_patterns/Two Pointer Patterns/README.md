# Two Pointers Patterns Overview

Two Pointers is a versatile technique used to solve a wide range of problems efficiently, particularly those involving arrays, strings, or linked lists. This overview categorizes the most common two pointer sub-patterns, their core ideas, and when to apply them.

<p align="center">
  <img src="https://github.com/dev-nzm99/DSA-Pathshala/blob/main/src/img/Screenshot%202025-11-03%20095609.png" alt="Two Pointer Illustration" width = "90%">
</p>

---

##  [1. Two Pointers - Converging (Sorted Array Target Sum)](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%20-%20Converging)

**Overview:**

* Two pointers start at opposite ends of a sorted array.
* Move the pointers toward each other based on comparison with the target sum.

**Use Cases:**

* Find two numbers that add up to a target.
* Detect pairs with specific sum or difference.

**Key Idea:**

* Utilize the sorted property to reduce time complexity to O(n).

**Example Problems:**

* Two Sum II - Input Array Is Sorted
* 3Sum Problem

---

##  [2. Two Pointers - Fast & Slow (Cycle Detection)](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%20-%20Fast%20%26%20Slow)

**Overview:**

* One pointer moves faster than the other (usually 2x speed).
* Used to detect cycles in linked lists or sequences.

**Use Cases:**

* Detect if a linked list has a cycle.
* Find the entry point of a cycle.

**Key Idea:**

* If fast meets slow, a cycle exists.

**Example Problems:**

* Linked List Cycle
* Linked List Cycle II

---

##  [3. Two Pointers - Fixed Separation (Nth Node from End)](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%20-%20Fixed%20Separation)

**Overview:**

* Maintain a fixed distance between two pointers.
* Commonly used for finding nodes from the end or middle.

**Use Cases:**

* Remove Nth node from the end of a list.
* Find the middle node of a linked list.

**Key Idea:**

* Fast pointer moves ahead by N steps; slow pointer follows. When fast reaches end, slow is at target.

**Example Problems:**

* Remove Nth Node From End of List
* Middle of the Linked List

---

## [4. Two Pointers - In-place Array Modification](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%3A%20In-place%20Array%20Modification)

**Overview:**

* Modify arrays directly without using extra space.
* One pointer scans, another writes.

**Use Cases:**

* Remove duplicates from sorted array.
* Move zeros to the end.
* Partition arrays (odd/even).

**Key Idea:**

* Fast/Slow pointers for order-preserving modifications.
* Left/Right pointers for partitioning.

**Example Problems:**

* Remove Duplicates from Sorted Array
* Move Zeroes
* Sort Colors (Dutch National Flag)

---

##  [5. Two Pointers - String Comparison with Backspaces](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%3A%20String%20Comparison%20with%20Backspaces)

**Overview:**

* Compare two strings considering backspace operations (#).
* Two pointers traverse strings from the end, simulating backspaces.

**Use Cases:**

* Compare user input after edits.
* Process undo operations efficiently.

**Key Idea:**

* Skip characters based on backspace count while comparing.

**Example Problems:**

* Backspace String Compare

---

##  [6. Two Pointers - Expanding From Center (Palindromes)](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%3A%20Expanding%20From%20Center%20(Palindromes))

**Overview:**

* Expand pointers from the center outward to check for palindromes.
* Handles both odd and even length palindromes.

**Use Cases:**

* Longest palindromic substring.
* Count all palindromic substrings.

**Key Idea:**

* Every palindrome has a center; expand around it to find valid substrings.

**Example Problems:**

* Longest Palindromic Substring
* Palindromic Substrings

---

##  [7. Two Pointers - String Reversal](https://github.com/dev-nzm99/dsalgo-lib/tree/main/all_DSA_patterns/Two%20Pointer%20Patterns/Two%20Pointers%3A%20String%20Reversal%20Subpattern)

**Overview:**

* Use two pointers from start and end to reverse a string in-place.

**Use Cases:**

* Reverse entire string.
* Reverse words in a sentence.
* Reverse specific segments.

**Key Idea:**

* Swap characters at two pointers and move pointers toward each other.

**Example Problems:**

* Reverse String
* Reverse Words in a String

---

This overview serves as a reference to quickly identify which two-pointer pattern fits a given problem and how to approach it effectively.
