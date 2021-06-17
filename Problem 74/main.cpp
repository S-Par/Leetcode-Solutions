#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Question: Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties: 
// Integers in each row are sorted in ascending from left to right
// The first integer of each row is greater than the last integer of the previous row.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Binary search: We can treat the 2D vector as a 1D sorted vector of size m x n
    // Then search it via binary search
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1, mid = -1; 
    int row = -1, col = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        // Converting 1D coordinate (mid) to row and col is:
        // mid = (row * n) + col
        col = mid % n;
        row = mid / n;
        if (matrix[row][col] == target) {
            return true;
        }
        // Look in the first half
        else if (matrix[row][col] > target) {
            end = mid - 1;
        }
        // Look in the last half
        else {
            start = mid + 1;
        }
    }

    // Didn't find target, return false
    return false;
}

int main() {
    vector<vector <int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    assert(searchMatrix(matrix, 3));
    assert(searchMatrix(matrix, 16));
    assert(searchMatrix(matrix, 60));
    assert(!searchMatrix(matrix, 2));
    assert(searchMatrix(matrix, 7));
    assert(!searchMatrix(matrix, 8));
    cout << "PASS!" << endl;
    return 0;
}