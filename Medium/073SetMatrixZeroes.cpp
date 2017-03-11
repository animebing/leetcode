// based on the solution of mzchen, https://discuss.leetcode.com/topic/5056/any-shorter-o-1-space-solution
// use the first element of each row to indicate whether there is 0 in each row. the first element in each 
// column to indicate whether there is 0 in each column, then matrix[0][0] will be used twice, so here matrix[0][0]
// represents whether there is 0 in row 0, use another variable col0 to indicate whether there is 0 in the first column
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool col0 = false;   // whether there is 0 in column 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 1; j--) {
                if (matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j] = 0;
            }
            if (col0) matrix[i][0] = 0;
        }
    }
};


// the solution of allen231x is almost the same as above, https://discuss.leetcode.com/topic/35647/21-lines-concise-and-easy-understand-c-solution-o-1-space-three-steps