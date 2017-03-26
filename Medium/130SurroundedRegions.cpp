// based on the solution of sugeladi, https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms
// but I write my code based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/18706/9-lines-python-148-ms
// check from the elements of boarder, if it is 'O', then change it to 'S', then check all neighbors of this element recursively
// after checking, all elements still with 'O' is ones surrounded by 'X', then change to 'X', all elements with 'S' are changed
// back to 'O'
// there will be run time error when submit solution, but if I only test the error case, there will not be run time error
// I can't  figure it why now, leave it here now
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        for (int col = 0; col < n; col++) check(board, 0, col);
        for (int row = 1; row < m; row++) check(board, row, n-1);
        for (int col = n-2; col >= 0; col--) check(board, m-1, col);
        for (int row = m-2; row >= 1; row--) check(board, row, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
private:
    void check(vector<vector<char>> &board, int row, int col) {
        int m = board.size(), n = board[0].size();
        if (board[row][col] == 'O') {
            board[row][col] = 'S';
            if (row-1 >= 0) check(board, row-1, col);
            if (row+1 < m) check(board, row+1, col);
            if (col-1 >= 0) check(board, row, col-1);
            if (col+1 < n) check(board, row, col+1);
        }
    }
};

// the solution of https://discuss.leetcode.com/topic/2982/my-bfs-solution-c-28ms is BFS version 
// there are find answer using union find, I don't know what it is now


// I make some change, but still run time error, it is ok now
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        for (int col = 0; col < n; col++) {
            if (board[0][col] == 'O') check(board, 0, col); 
            if (board[m-1][col] == 'O') check(board, m-1, col);
        }

        for (int row = 1; row <= m-2; row++) {
            if (board[row][0] == 'O') check(board, row, 0);
            if (board[row][n-1] == 'O') check(board, row, n-1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
private:
    void check(vector<vector<char>> &board, int row, int col) {
        int m = board.size(), n = board[0].size();
        board[row][col] = 'S';
        if (row-1>=1 && board[row-1][col]=='O') check(board, row-1, col); // i change the boarder condition
        if (row+1<m-1 && board[row+1][col]=='O') check(board, row+1, col);
        if (col-1>=1 && board[row][col-1]=='O') check(board, row, col-1);
        if (col+1<n-1 && board[row][col+1]=='O') check(board, row, col+1);
        
    }
};