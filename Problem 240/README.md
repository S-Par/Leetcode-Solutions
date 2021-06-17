## Problem 240: Search a 2D Matrix II
- Difficulty Level: Medium 

Write an efficient algorithm that searches for a value `target` in an `m x n` matrix.  
This matrix has the following properties:
1. Integers in each row are sorted in ascending order from left to right.
2. Integers in each column are sorted in ascending order from top to bottom. 

#### Constraints:
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `-10^9 <= matrix[i][j], target <= 10^9`

---
### Examples:
```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```

---
### Solution:
1. Start out in the bottom-left corner of the 2D matrix and move right until you hit a value greater than `target`
2. Move up until you hit a value lower than `target`
3. Repeat steps 1 and 2 until you either find target or go out of bounds. If you go out of bounds, return false.
