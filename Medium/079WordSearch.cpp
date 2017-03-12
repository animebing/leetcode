// backtracking, but time limit exceeded
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> flag(m, vector<bool>(n, false));
                    flag[i][j] = true;
                    string com;
                    com.push_back(word[0]);
                    if (helper(board, flag, word, com, i, j)) return true;
                }
            }
        }
        return false;
    }
private: 
    bool helper(vector<vector<char>> &board, vector<vector<bool>> &flag, string &word, string &com, int row, int col) {
        if (com.size() == word.size()) {
            if (com == word) return true;
            else return false;
        }
        // up
        if (row-1>=0 && flag[row-1][col]==false) {
            com.push_back(board[row-1][col]);
            flag[row-1][col] = true;
            if (helper(board, flag, word, com, row-1, col)) return true;
            flag[row-1][col] = false;
            com.pop_back();
        }
        // down
        if (row+1<board.size() && flag[row+1][col]==false) {
            com.push_back(board[row+1][col]);
            flag[row+1][col] = true;
            if (helper(board, flag, word, com, row+1, col)) return true;
            flag[row+1][col] = false;
            com.pop_back();
        }
        // left
        if (col-1>=0 && flag[row][col-1]==false) {
            com.push_back(board[row][col-1]);
            flag[row][col-1] = true;
            if (helper(board, flag, word, com, row, col-1)) return true;
            flag[row][col-1] = false;
            com.pop_back();
        }
        // right
        if (col+1<board[0].size() && flag[row][col+1]==false) {
            com.push_back(board[row][col+1]);
            flag[row][col+1] = true;
            if (helper(board, flag, word, com, row, col+1)) return true;
            flag[row][col+1] = false;
            com.pop_back();
        }
        
        return false;
    }
};

// same as above, but with pruning, only when next letter is same as that in the word, I will add it
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> flag(m, vector<bool>(n, false));
                    flag[i][j] = true;
                    string com;
                    com.push_back(word[0]);
                    if (helper(board, flag, word, com, i, j)) return true;
                }
            }
        }
        return false;
    }
private: 
    bool helper(vector<vector<char>> &board, vector<vector<bool>> &flag, string &word, string &com, int row, int col) {
        if (com.size() == word.size()) return true;
        // up
        int n = com.size();
        if (row-1>=0 && !flag[row-1][col] && board[row-1][col]==word[n]) { // 
            com.push_back(board[row-1][col]);
            flag[row-1][col] = true;
            if (helper(board, flag, word, com, row-1, col)) return true;
            flag[row-1][col] = false;
            com.pop_back();
        }
        // down
        if (row+1<board.size() && !flag[row+1][col] && board[row+1][col]==word[n]) {
            com.push_back(board[row+1][col]);
            flag[row+1][col] = true;
            if (helper(board, flag, word, com, row+1, col)) return true;
            flag[row+1][col] = false;
            com.pop_back();
        }
        // left
        if (col-1>=0 && !flag[row][col-1] && board[row][col-1]==word[n]) {
            com.push_back(board[row][col-1]);
            flag[row][col-1] = true;
            if (helper(board, flag, word, com, row, col-1)) return true;
            flag[row][col-1] = false;
            com.pop_back();
        }
        // right
        if (col+1<board[0].size() && !flag[row][col+1] && board[row][col+1]==word[n]) {
            com.push_back(board[row][col+1]);
            flag[row][col+1] = true;
            if (helper(board, flag, word, com, row, col+1)) return true;
            flag[row][col+1] = false;
            com.pop_back();
        }
        
        return false;
    }
};



// based on the solution of dong.wang.1694 and bumingqiu, https://discuss.leetcode.com/topic/19658/my-dfs-backtracking-c-solution-16ms/6
// above solution is starting at [i, j], but here check [i, j] first, then spread around four directions
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helper(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private: 
    bool helper(vector<vector<char>> &board, string &word, int row, int col, int idx) {
        if (board[row][col] == word[idx]) {
            if (idx == word.size()-1) return true;
            char tmp = board[row][col];
            board[row][col] = '*';
            if (row-1>=0 && helper(board, word, row-1, col, idx+1)) return true;
            if (row+1<board.size() && helper(board, word, row+1, col, idx+1)) return true;
            if (col-1>=0 && helper(board, word, row, col-1, idx+1)) return true;
            if (col+1<board[0].size() && helper(board, word, row, col+1, idx+1)) return true;
            board[row][col] = tmp;
        }
        return false;
    }
};