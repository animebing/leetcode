// similar to Unique Path I,but here for the first row and first column of dp, the initialization is different
// when the grid is an obstacle, then all grids following can not be visited in the first row and first column
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1]) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 0) dp[0][j] = 1;
            else break;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {  // more careful, the fist submission, i wrote i++ here, the runtime error occurs
                if (obstacleGrid[i][j]) dp[i][j] = 0; // no need for obstacle grip, because it is initialized to 1
                else dp[i][j] = dp[i][j-1] + dp[i-1][j];  // no need to consider whether [i, j-1] or [i-1, j] is an obstacle
            }
        }
        return dp[m-1][n-1];
    }
};

// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15267/4ms-o-n-dp-solution-in-c-with-explanations
// use two column to store the result of previous column and current column
// use flag to indicate whether there is one element which can be reached in current column, otherwise return 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1]) return 0;
        vector<int> prev(m, 0), cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0]) prev[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {
                cur[0] = prev[0];   // clever here to get cur[0] using prev[0]
                if (cur[0]) flag = true;
            } else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] = prev[i] + cur[i-1];
                    if (cur[i]) flag = true;
                } else cur[i] = 0;
            }
            if (!flag) return 0;
            prev = cur;
        }
        return prev[m-1];
    }
};

// just use one vector
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1]) return 0;
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0]) cur[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {  
                if (cur[0]) flag = true;
            } else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i-1];
                    if (cur[i]) flag = true;
                } else cur[i] = 0;
            }
            if (!flag) return 0;
        }
        return cur[m-1];
    }
};