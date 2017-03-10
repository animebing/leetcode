// dynamic programming, dp[i][j] represents the mnnimum path sum to [i, j] then dp[i][j] = min(dp[i][j-1]+grid[i][j], dp[i-1][j]+grid[i][j])
// below is the implementation using just one column
#include <algorithm>  // for min
#include <vector>  // for vector
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, 0);
        cur[0] = grid[0][0];
        for (int i = 1; i < m; i++) cur[i] = grid[i][0] + cur[i-1];
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++) cur[i] = min(cur[i]+grid[i][j], cur[i-1]+grid[i][j]);
        }
        return cur[m-1];
    }
};