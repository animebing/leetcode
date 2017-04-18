// start from top right or left bottom, when the element is equal to target, then return true, or go the next row, or previous column
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n-1;
        while (row<m && col>=0) {
            int tmp = matrix[row][col];
            if (tmp == target) return true;
            if (tmp < target) row++;
            else col--;
        }
        return false;
    }
};