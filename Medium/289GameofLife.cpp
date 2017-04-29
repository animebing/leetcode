// naive solution with replicate board
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> tmp(board);
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                if (i-1 >= 0) cnt += tmp[i-1][j];
                if (i-1>=0 && j+1<n) cnt += tmp[i-1][j+1];
                if (j+1 < n) cnt += tmp[i][j+1];
                if (i+1<m && j+1<n) cnt += tmp[i+1][j+1];
                if (i+1 < m) cnt += tmp[i+1][j];
                if (i+1<m && j-1>=0) cnt += tmp[i+1][j-1];
                if (j-1 >= 0) cnt += tmp[i][j-1];
                if (i-1>=0 && j-1>=0) cnt += tmp[i-1][j-1];
                if (tmp[i][j] == 1) {
                    if (cnt < 2) board[i][j] = 0;
                    if (cnt > 3) board[i][j] = 0;
                } else {
                    if (cnt == 3) board[i][j] = 1;
                }
            }
        }
    }
};





// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/26112/c-o-1-space-o-mn-time
// use the 2-bit to store the new state 
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = -board[i][j]; // state in board[i][j]
                for (int I = max(i-1, 0); I < min(i+2, m); I++) 
                    for (int J = max(j-1, 0); J < min(j+2, n); J++) cnt += board[I][J]&1;  // cnt of live including board[i][j]
                if ((cnt | board[i][j]) == 3) board[i][j] |= 2;  // new state is 1 (live), for other case,it is 0
            }
        }
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) board[i][j] >>= 1;  // get the new state
    }
};