## Problem 74: Search a 2D Matrix
- Difficulty Level: Medium 

Write an efficient algorithm that searches for a value in an `m x n` matrix.  
This matrix has the following properties:
1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.

#### Constraints:
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

---
### Examples:
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

---
### Solution:
1. Due to the properties of this 2D vector, we can visualize this as a sorted 1D vector of size `m x n`.
2. Perform a binary search for the target (converting the 1D coordinate to the appropriate row and column indices)
