// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/21090/0ms-clear-c-solution
// clean solution to record upper, bottom, left and right
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m*n);
        int u = 0, b = m-1, l = 0, r = n-1, k = 0;
        while (1) {
            for (int col = l; col <= r; col++) res[k++] = matrix[u][col];
            if (++u > b) break;
            for (int row = u; row <= b; row++) res[k++] = matrix[row][r];
            if (--r < l) break;
            for (int col = r; col >= l; col--) res[k++] = matrix[b][col];
            if (--b < u) break;
            for (int row = b; row >= u; row--) res[k++] = matrix[row][l];
            if (++l > r) break;
        }
        return res;
    }
    
};