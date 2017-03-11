// the matrix can be regarded as a sorted vector, then use binary search to check whether the element is in the matrix
// when the mid is computed, then compute the corresponding row and col index to access the element
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        long low = 0, high = m*n-1;
        while (low <= high) {
            long mid = low + (high-low)/2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};