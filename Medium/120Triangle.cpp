// intuitive solution, for each element in current row, I just need to access two elements in next level
// this DFS solution, Time Limit Exceeded
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int res = INT_MAX;
        helper(triangle, n-1, 0, 0, triangle[0][0], res);
        return res;
    }
private:
    void helper(vector<vector<int>> & triangle, int rows, int cur_row, int idx, int sum, int &res) {
        if (cur_row == rows) {
            if (sum < res) res = sum;
            return;
        }
        
        helper(triangle, rows, cur_row+1, idx, sum+triangle[cur_row+1][idx], res);
        helper(triangle, rows, cur_row+1, idx+1, sum+triangle[cur_row+1][idx+1], res);
    }
};

// dp solution, for level i(i is indexed from 0) , dp[0] to dp[i] represent the minimum sum from top to elment i 
// in level i(triangle[i])
// this is an top-down solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) dp[j] = dp[j-1]+triangle[i][j];
                else if (j == 0) dp[j] = dp[0] + triangle[i][0];
                else dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
        }
        int res = INT_MAX;
        for (int v:dp) {
            if (v < res) res = v;
        }
        return res;
    }
};

// based on the solution of stellari, https://discuss.leetcode.com/topic/1669/dp-solution-for-triangle
// bottom-up dp solution, dp[i] represents the minimum path sum from i to the last level
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back());
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) 
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        }
        return dp[0];
    }
};