# Prefix Sum Subpattern: Using Hash Map  

## 1. Pattern Overview  

Imagine you’re walking along a road, keeping track of how far you’ve walked so far.  
At every step, you look back and ask:

> “Have I ever walked such that the distance between *that* time and *now* is exactly K?”

Instead of recomputing distances again and again, you keep a running total and a notebook listing distances you’ve seen before. This is the essence of the **Prefix Sum + Hash Map** pattern.

Unlike a simple prefix sum array (where you only precompute sums and query with indices), here you:

- Maintain a **running cumulative sum**, and  
- Use a **hash map** to remember what sums you’ve seen before and how many times.

This pattern is incredibly useful when you need to work with **subarrays** whose:

- Sum equals a given target `K`
- Sum satisfies some modular property (e.g., divisible by `K`)
- Sum equals `0` (for balance problems)
- Longest/shortest subarray meets a sum-based condition

Everyday analogy:  
Think of tracking your **bank account balance** over days. Each day you note your total balance (prefix sum). Later, you might ask:  
> “On how many intervals did my net change in balance equal +1000?”  

By comparing differences between balances on two days, you can answer this without recalculating everything. The hash map is your logbook of past balances.

---

## 2. Core Concepts  

### How the Pattern Works  

1. **Running Prefix Sum**  
   You iterate through the array and maintain:  
   `sum = arr[0] + arr[1] + ... + arr[i]`  

2. **Key Equation for Subarray Sum**  
   For subarray `arr[l..r]`:

   ```text
   sum(l, r) = prefixSum(r) - prefixSum(l - 1)

