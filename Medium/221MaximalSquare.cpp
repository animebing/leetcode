// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
// dp solution, dp[i][j] means the maximum size of square where [i, j] is in the right-bottom of the square
// then for leftmost and topmost of dp[i][j], dp[i][j] = matrix[i][j]-'0'. for others, when matrix[i][j] = '0', dp[i][j] = 0, otherwise, 
// dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_size = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                max_size = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                max_size = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1; // ----------------------------
                    if (dp[i][j] > max_size) max_size = dp[i][j];  // ------------------------
                }
            }
        }
        return max_size*max_size;
    }
};



// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
// only use two rows
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> pre(n, 0);
        vector<int> cur(n, 0);
        int max_size = 0;
        for (int j = 0; j < n; j++) {
            pre[j] = matrix[0][j]-'0';
            max_size = max(max_size, pre[j]);
        }
        for (int i = 1; i < m; i++) {
            cur[0] = matrix[i][0] - '0';
            max_size = max(max_size, cur[0]);
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    cur[j] = min(min(pre[j], cur[j-1]), pre[j-1])+1;
                    max_size = max(max_size, cur[j]);
                }
            }
            swap(pre, cur);
            fill(cur.begin(), cur.end(), 0);
        }
        return max_size*max_size;
    }
};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
// only use one row
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cur(n, 0);
        
        int max_size = 0;
        for (int j = 0; j < n; j++) {
            cur[j] = matrix[0][j]-'0';
            max_size = max(max_size, cur[j]);
        }
        for (int i = 1; i < m; i++) {
            int pre = cur[0];   // use pre to store the corresponding value in previous row
            cur[0] = matrix[i][0] - '0';
            max_size = max(max_size, cur[0]);
            for (int j = 1; j < n; j++) {
                int tmp = cur[j];  // keep value of previous row
                if (matrix[i][j] == '1') {
                    cur[j] = min(min(cur[j], cur[j-1]), pre)+1;
                    max_size = max(max_size, cur[j]);
                } else cur[j] = 0;
                pre = tmp;
            }
        }
        return max_size*max_size;
    }
};