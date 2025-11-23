# Prefix Sum Subpattern: Using Hash Map  

## 1. Pattern Overview  

Imagine you’re walking along a road, keeping track of how far you’ve walked so far.  
At every step, you look back and ask:

> “Have I ever walked such that the distance between *that* time and *now* is exactly `K`?”

Instead of recomputing distances again and again, you keep a **running total** and a **notebook** listing distances you’ve seen before.  
This is the essence of the **Prefix Sum + Hash Map** pattern.

Unlike a simple prefix sum array (where you only precompute sums and then answer range queries), here you:

- Maintain a **running cumulative sum**, and  
- Use a **hash map** to remember what sums you’ve seen before and how many times (or where).

This pattern is incredibly useful when you need to work with **subarrays** whose:

- Sum equals a given target `K`
- Sum equals `0` (e.g., balance / difference problems)
- Sum satisfies some modular property (e.g., divisible by `K`)
- Longest / shortest subarray meets a sum-based condition

**Everyday analogy:**  
Think of tracking your **bank account balance** over days. Each day you note your total balance (prefix sum). Later, you might ask:  

> “On how many intervals did my net change in balance equal +1000?”  

By comparing differences between balances on two days, you can answer this without recalculating every transaction.  
The hash map is your **logbook of past balances**.

<p align="center">
  <img src="https://github.com/dev-nzm99/DSA-Pathshala/blob/main/src/img/Prefix%20sum%2Bhash%20map.png" width="700">
</p>


---

## 2. Core Concepts  

### 2.1 Running Prefix Sum  

As you iterate through the array, maintain a cumulative sum:

```text
prefixSum(i) = arr[0] + arr[1] + ... + arr[i]
```

You usually keep it in a single variable, e.g.:

```cpp
long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += arr[i];
    // use sum with hash map here
}
```

No need to store all prefix sums in an array unless required; one running sum is enough when used with a hash map.

---

### 2.2 Key Equation for Subarray Sum  

For a subarray `arr[l..r]` (0-based indices):

```text
sum(l, r) = prefixSum(r) - prefixSum(l - 1)
```

If you want:

```text
sum(l, r) = K
```

then:

```text
prefixSum(r) - prefixSum(l - 1) = K
⇒ prefixSum(l - 1) = prefixSum(r) - K
```

So, when you are at index `r` with current sum:

```text
S = prefixSum(r)
```

you just need to know:

> **How many times have we seen `S - K` before as a prefix sum?**

Every such occurrence of `S - K` corresponds to a starting point `l` that gives a subarray `arr[l..r]` with sum `K`.

This is where the **hash map** comes in.

---

## 3. Role of the Hash Map  

The hash map (e.g., in C++ `unordered_map<long long, int>`) usually stores one of the following, depending on the problem:

### 3.1 `sum → frequency`  

- **Meaning:** How many prefixes have this exact sum.
- **Use case:** Counting the **number of subarrays** with a given sum `K`.

Example key idea:

```text
map[sum] = how many times this prefix sum has appeared so far
```

At each index `i` with current sum `S`:

- The number of subarrays ending at `i` with sum `K` is `map[S - K]`.
- Then update: `map[S]++`.

---

### 3.2 `sum → earliest index`  

- **Meaning:** The first index where this prefix sum appeared.
- **Use case:** Finding the **longest subarray** with sum `K` (or sum `0`).

Key idea:

- If at index `i` you have `prefixSum(i) = S`, and in the past at index `j` you also had `prefixSum(j) = S - K`, then:
  - Subarray from `(j+1)` to `i` has sum `K`.
- Storing the **earliest** index for each sum allows you to maximize subarray length.

---

### 3.3 `(sum % K) → frequency / index`  

- **Meaning:** How many prefixes have remainder `r` (`0 ≤ r < K`) when divided by `K`, or the earliest index with that remainder.
- **Use case:** Problems where **subarray sum must be divisible by `K`**, or other modular constraints.

Key idea:

- If:

  ```text
  prefixSum(i) % K = prefixSum(j) % K
  ```

  then:

  ```text
  sum(j+1, i) = prefixSum(i) - prefixSum(j)
  ```

  is divisible by `K`.

---

## 4. Time & Space Complexity  

### 4.1 Time Complexity  

- Single pass through the array: `O(N)`
- Each hash map operation (search/insert/update) is **average** `O(1)`  
  (amortized, assuming good hash function and no extreme collisions)

So overall:

```text
Time: O(N)
```

This is much better than the naive `O(N²)` approach of checking all subarrays.

---

### 4.2 Space Complexity  

- The hash map can store up to `O(N)` distinct prefix sums or remainders.

So:

```text
Space: O(N)
```

---

## 5. Mathematical Foundation  

At its core, the pattern rests on a simple but powerful idea:

> **Subarray sums are differences of prefix sums.**

Formally, for any `l ≤ r`:

```text
sum(l, r) = prefixSum(r) - prefixSum(l - 1)
```

Rewriting conditions as **equations between prefix sums** allows you to:

- Replace nested loops with a **single scan**.
- Use a hash map to **remember history** of prefix sums (or remainders).
- Turn many “find how many subarrays satisfy X” problems into:
  - “Count how many times some transformed value has appeared before.”

This pattern also works with:

- Negative numbers
- Zeros
- Mixed values

—as long as you carefully define what you store in the hash map.

---

## 6. Implementation Approach  

### 6.1 Pattern Recognition  

Ask yourself:

- Am I dealing with **subarrays** (contiguous segments)?
- Is the condition about the **sum** of elements (possibly with a target `K` or divisibility)?
- Do I need to count subarrays, check existence, or find longest length?

If **yes**, the **Prefix Sum + Hash Map** pattern is very likely applicable.

---

### 6.2 Template 1: Count Subarrays with Sum = `K`  

**Goal:** Number of subarrays whose sum equals `K`.

**Key idea:**

- Let `S` be the current prefix sum.
- For each index, the number of valid subarrays ending here is `freq[S - K]`.

**Pseudocode (C++-style):**

```cpp
int countSubarraysSumK(vector<int>& nums, int K) {
    unordered_map<long long, int> freq;
    long long sum = 0;
    int count = 0;

    // Important: one empty prefix with sum 0
    freq[0] = 1;

    for (int x : nums) {
        sum += x;

        long long need = sum - K;
        if (freq.count(need)) {
            count += freq[need];
        }

        freq[sum]++;  // record this prefix sum
    }

    return count;
}
```

**Key details:**

- `freq[0] = 1` handles subarrays starting at index `0`.
- Works with negative numbers as well.

---

### 6.3 Template 2: Longest Subarray with Sum = `K`  

**Goal:** Find maximum length of a subarray with sum exactly `K`.

**Key idea:**

- Use `sum → earliestIndex` map.
- At index `i` with prefix sum `S`, we want earliest index `j` where `prefixSum(j) = S - K`.

**Pseudocode:**

```cpp
int longestSubarraySumK(vector<int>& nums, int K) {
    unordered_map<long long, int> firstIndex;
    long long sum = 0;
    int maxLen = 0;

    // prefix sum 0 at index -1 (before array starts)
    firstIndex[0] = -1;

    for (int i = 0; i < (int)nums.size(); i++) {
        sum += nums[i];

        long long need = sum - K;

        if (firstIndex.count(need)) {
            int len = i - firstIndex[need];
            maxLen = max(maxLen, len);
        }

        // store earliest index only
        if (!firstIndex.count(sum)) {
            firstIndex[sum] = i;
        }
    }

    return maxLen;
}
```

---

### 6.4 Template 3: Subarray Sum Divisible by `K`  

**Goal:** Check if there exists (or count) subarray(s) whose sum is divisible by `K`.

**Key idea:**

- Store `(sum % K) → frequency` or index.
- If the same remainder appears twice, the subarray between them is divisible by `K`.

**Pseudocode (existence check):**

```cpp
bool hasSubarrayDivisibleByK(vector<int>& nums, int K) {
    unordered_map<int, int> firstIndex;
    long long sum = 0;

    // remainder 0 at index -1
    firstIndex[0] = -1;

    for (int i = 0; i < (int)nums.size(); i++) {
        sum += nums[i];
        int r = (int)(sum % K);
        if (r < 0) r += K;  // handle negative sums

        if (firstIndex.count(r)) {
            // subarray from firstIndex[r] + 1 to i has sum divisible by K
            if (i - firstIndex[r] >= 1) { // or >= 2 based on problem
                return true;
            }
        } else {
            firstIndex[r] = i;
        }
    }

    return false;
}
```

---

### 6.5 Edge Cases to Remember  

- **Initialize map correctly**:
  - `freq[0] = 1` for counting subarrays sum `K`.
  - `firstIndex[0] = -1` for longest subarray or divisibility checks.
- **Negative numbers**:
  - Direct prefix sums are fine.
  - For modulo, normalize remainder: `((sum % K) + K) % K`.
- **Empty array or no valid subarray**:
  - Count = 0, or length = 0, or return `false`, depending on problem.

---

## 7. How to Think During a Problem  

You can mentally follow this checklist:

1. **Is this about subarray sums / ranges?**
2. **Can I express the condition using `prefixSum(r) - prefixSum(l - 1)`?**
3. **What do I need to store in the map?**
   - Count of prefixes? → frequency
   - First occurrence? → earliest index
   - Remainders? → modulo variant
4. **Do I need:**
   - Number of subarrays?
   - Existence of at least one subarray?
   - Longest or shortest subarray?

Once this is clear, your implementation becomes a direct application of one of the templates above.

---

## 8. Practice Problems  

### Basics
- [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

### Counting Problems
- [930. Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/)
- [1248. Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)

### Bitmask Variants
- [1915. Number of Wonderful Substrings](https://leetcode.com/problems/number-of-wonderful-substrings/)
- [1371. Longest Substring with Vowels in Even Counts](https://leetcode.com/problems/longest-substring-with-vowels-in-even-counts/)

### Longest Subarray
- [Longest Subarray with Sum K (GFG)](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)
- [Minimum Removals for Target Sum (GFG)](https://www.geeksforgeeks.org/problems/minimum-removals-for-target-sum/1)
- [525. Contiguous Array](https://leetcode.com/problems/contiguous-array/)
- [325. Maximum Size Subarray Sum Equals K](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)

### Tricky Variations
- [1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)
- [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

### Check If Subarray Exists
- [523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/)
- [1124. Longest Well-Performing Interval](https://leetcode.com/problems/longest-well-performing-interval/)

### Advanced Challenges
- [1542. Longest Awesome Substring](https://leetcode.com/problems/longest-awesome-substring/)
- [2389. Longest Subsequence With Limited Sum](https://leetcode.com/problems/longest-subsequence-with-limited-sum/)

---

By mastering the **Prefix Sum + Hash Map** subpattern, you gain a powerful tool for many range and subarray problems that would otherwise require `O(N²)` brute-force solutions.
