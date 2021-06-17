#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Question: Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties: 
// Integers in each row are sorted in ascending from left to right
// Integers in each column are sorted in ascending from top to bottom.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Linear stepwise search: (movements until you hit target)
    // Start at the bottom-left, move right until you hit a value greater than the target
    // then move up until you reach a value lower than the target then right again
    // If you hit the right edge without finding target, return false
    int m = matrix.size(), n = matrix[0].size();
    int row = m - 1, col = 0;
    while (row >= 0 && col < n) {
        if (matrix[row][col] == target) {
            return true;
        }
        else if (matrix[row][col] > target) {
            --row;
        }
        else {
            ++col;
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