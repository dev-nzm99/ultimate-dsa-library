# Two Pointers Pattern: String Comparison with Backspaces

## 1. Pattern Overview

Imagine you’re typing a message on your phone, but you keep making mistakes and hitting the backspace key (#). Now, suppose your friend is typing a different message, also making mistakes and using backspace. If you both show your final messages, how can you tell if you ended up with the same text—even though you made different mistakes along the way?

This is the heart of the **String Comparison with Backspaces** subpattern, a practical twist on the classic **Two Pointers** technique. Instead of just comparing two strings character by character, you have to simulate how each string would look after all the backspaces are processed—just like watching someone type and erase on a notepad.

This pattern is especially useful when you need to simulate editing actions efficiently, such as:

* Comparing user input with typo corrections
* Processing undo operations in text editors
* Handling real-time chat corrections

Everyday analogy: Think of two people writing notes on paper, but every time they make a mistake, they cross out the last letter. At the end, you want to check if their final notes are the same, regardless of how many mistakes or corrections they made.

---

## 2. Core Concepts

### Two Pointers

* **What is it?** Using two markers (pointers) to traverse data structures (like arrays or strings) from different ends or at different speeds.
* **Why use it here?** Because we want to compare two strings after simulating backspaces, but we don’t want to actually build the final strings if we can avoid it.

### Simulation

* **What does “simulation” mean?** Acting out the process as if you were typing and erasing, step by step.
* **How do we simulate backspaces?** By moving backwards through the string and skipping characters that would have been erased.

### Stack (Alternative Approach)

* **What is a stack?** A structure where you can “push” (add) and “pop” (remove) items in a last-in, first-out order.
* **How does it help?** You can build the final string by pushing characters and popping when you see a backspace.

### Time and Space Complexity

* **Stack approach:** O(N) time, O(N) space.
* **Two pointers approach:** O(N) time, O(1) extra space.
* Analogy: Reading page by page vs flipping backwards and skipping crossed-out pages.

### Mathematical Foundation

* Counting backspaces: As you move backwards, keep a counter for backspaces and skip characters until counter is zero.

---

## 3. Implementation Approach

### Think Like This

* Do I need to compare two strings after simulating edits (like backspaces)?
* Can I avoid building the final strings? If yes, use two pointers.

### Step-by-Step Approach

1. **Start from the end:** Place a pointer at the last character of each string.
2. **Process backspaces:**

   * If you see `#`, increase backspace counter.
   * If you see a letter and counter > 0, skip it and decrement counter.
   * If you see a letter and counter == 0, this is the next valid character.
3. **Compare characters:** Once valid characters from both strings are found, compare them.

   * If different → strings aren’t equal.
   * If same → move both pointers back and repeat.

### Handle Edge Cases

* One string might finish before the other.
* Multiple consecutive backspaces at the start or end.
* Empty strings or strings with only backspaces.

### Decision Tree

* Need final string? Use stack.
* Only need to compare? Use two pointers.

### Example Edge Case

* `s = "a#b#c#"` and `t = "###"` → both become empty strings.

### Visual Walkthrough

* Imagine two people erasing letters from the end of their notes. You watch them both, moving backwards, and only compare the letters that remain after all erasing is done.

---

## 🧩 PRACTICE PROBLEMS

1. **Backspace String Compare**

   * [LeetCode Link](https://leetcode.com/problems/backspace-string-compare/)

2. **Compare Version Numbers**

   * [LeetCode Link](https://leetcode.com/problems/compare-version-numbers/)

3. **Valid Parentheses** (Alternative stack simulation)

   * [LeetCode Link](https://leetcode.com/problems/valid-parentheses/)

By practicing these problems, you'll master the **String Comparison with Backspaces** subpattern and efficiently solve string simulation challenges using two pointers.
