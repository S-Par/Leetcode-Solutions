## Problem 4: Median of Two Sorted Arrays
- Difficulty Level: Hard 

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the **median** of the two sorted arrays.

---
### Examples:
```
Input: nums1 = [1,3], nums2 = [2] 
Output: 2.00000  
Explanation: merged array = [1,2,3] and median is 2. 
```

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

```
Input: nums1 = [], nums2 = [1]
Output: 1.00000
```
---
### Solution:
1. Check if one of the two arrays is empty, if so, return the median of the non-empty array instantly.
2. Build a third array which is a sorted combination of the two (but only up to the values relevant for the median)
3. Calculate the median and return it
