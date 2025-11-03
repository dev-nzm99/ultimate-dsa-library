# Two Pointers Pattern: String Reversal Subpattern

## 1. Pattern Overview

Imagine you have a necklace with beads, and you want to reverse the order of the beads without taking them all off. Instead, you start swapping the bead at one end with the bead at the other, moving inwards until you meet in the middle. This is the essence of the Two Pointers pattern, especially in the context of **String Reversal**.

In programming, strings are sequences of characters—think of them as a row of tiles. Sometimes, we need to reverse the entire sequence, flip specific parts, or selectively reverse certain characters (like vowels). Real-world scenarios include undoing user input, formatting text, or processing data for algorithms. Common problems: **Reverse String**, **Reverse Vowels of a String**, **Reverse Words in a String**.

The Two Pointers approach is efficient: process the string from both ends simultaneously, reducing operations and memory usage.

---

## 2. Core Concepts

### Two Pointers

* **Left pointer:** starts at the beginning.
* **Right pointer:** starts at the end.
* Swap characters as pointers move toward each other.

### In-Place Modification

* Modify the original string directly without creating extra arrays.

### Step-by-Step Process

1. Place `left` at start and `right` at end.
2. While `left < right`, swap characters at `left` and `right`.
3. Move `left` forward, `right` backward.
4. Repeat until pointers meet or cross.

### Time Complexity

* O(n), each character visited at most once.

### Space Complexity

* O(1), only a few pointers/variables.

### Selective Reversal

* Reverse only specific characters (e.g., vowels).
* Pointers may skip non-targets.

### Mathematical Foundation

* Symmetry: swap i-th and (n-1-i)-th elements; each pair handled once.

---

## 3. Implementation Approach

### Think Like This

* What is being reversed? Whole string, certain characters, or sections?
* Can processing from both ends help? If yes, Two Pointers applies.
* Is in-place modification required?

### Step-by-Step Approach

1. **Identify Range:** Start and end pointers.
2. **Set Up Pointers:** Initialize `left` and `right`.
3. **Loop and Swap:**

   * While `left < right`:

     * Skip non-targets if selective reversal.
     * Swap characters at `left` and `right`.
     * Move `left` forward, `right` backward.

### Edge Cases

* Empty string → nothing to reverse.
* Single character → already reversed.
* Odd/even length → middle character stays for odd length.
* Selective reversal → only swap target characters.

### Decision Tree

* Whole string reversal → classic Two Pointers.
* Certain characters → add conditions to skip non-targets.
* Sections → loop through chunks, apply Two Pointers per chunk.

### Example Edge Case

* **Reverse Vowels:** "hello" → only 'e' and 'o' swapped → "holle".

---

## 🧩 PRACTICE PROBLEMS

1. **Reverse String**

   * [LeetCode Link](https://leetcode.com/problems/reverse-string/)

2. **Reverse Vowels of a String**

   * [LeetCode Link](https://leetcode.com/problems/reverse-vowels-of-a-string/)

3. **Reverse Words in a String**

   * [LeetCode Link](https://leetcode.com/problems/reverse-words-in-a-string/)

By practicing these problems, you'll master the **String Reversal** subpattern using Two Pointers and efficiently reverse, rearrange, or selectively process strings.
