// brute-force, check each row, column and each grid to see whether one number has occured

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for (int i = 0; i < 9; i++){
            int cnt[9] = {0};
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    int tmp = board[i][j]-'0'-1;
                    cnt[tmp]++;
                    if (cnt[tmp] == 2) return false;
                }
            }
        }
        // column check
        for (int i = 0; i < 9; i++){
            int cnt[9] = {0};
            for (int j = 0; j < 9; j++){
                if (board[j][i] != '.'){
                    int tmp = board[j][i]-'0'-1;
                    cnt[tmp]++;
                    if (cnt[tmp] == 2) return false;
                }
            }
        }
        // grid check
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int cnt[9] = {0};
                for (int m = 3*i; m < 3*(i+1); m++) {
                    for (int n = 3*j; n < 3*(j+1); n++) {
                        if (board[m][n] != '.') {
                            int tmp = board[m][n]-'0'-1;
                            cnt[tmp]++;
                            if (cnt[tmp] == 2) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

/* check row, col, grid together
    amazing thing here are:
    1. use bit operation to check whether a digit has occurred once , how?
    `   (1) the bit operation of row indicates whether a digit has occurred, 0:no, 1:yes. every time when a digit comes, we will
        left shift digit's bit on 1, then do & operation, if the result is 0, it means that the digit has not occurred, otherwise
        it has occurred, then return false. if the result is 0, we need to embed the information into row, we use | operation to 
        finish this. it is really coooooooool.
    2. grid check in the same loop, which indicates variable 'i' in first loop has different meaning. row index, column index and
    index. i don't know how to transfer the grid index to vector index at first, but i know how it works now
        i/3, i%3 determine the grid row and column index
        j/3, j%3 determine the row and column index in one grid
*/ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            int row = 0, col = 0, grid = 0;
            for (int j = 0; j < 9; j++){
                // row check
                if (board[i][j] != '.'){
                    int tmp = 1<<(board[i][j]-'0');
                    if (row & tmp) return false;
                    row |= tmp;
                }
                
                // column check
                if (board[j][i] != '.'){
                    int tmp = 1<<(board[j][i]-'0');
                    if (col & tmp) return false;
                    col |= tmp;
                }
                
                // grid check
                int x = i/3*3 + j/3;  
                int y = i%3*3 + j%3;
                if (board[x][y] != '.'){
                    int tmp = 1<<(board[x][y]-'0');
                    if (grid & tmp) return false;
                    grid |= tmp;
                }
            }
        }
        return true;
    }
};

// use the container bitset in C++ to check whether a digit has occurred before.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            bitset<9> row, col, grid;
            for (int j = 0; j < 9; j++){
                // row check
                if (board[i][j] != '.'){
                    int idx = board[i][j]-'1';
                    if (row.test(idx)) return false;
                    row.set(idx);
                }
                
                // column check
                if (board[j][i] != '.'){
                    int idx = board[j][i]-'1';
                    if (col.test(idx)) return false;
                    col.set(idx);
                }
                
                // grid check
                int x = i/3*3 + j/3;  
                int y = i%3*3 + j%3;
                if (board[x][y] != '.'){
                    int idx = board[x][y]-'1';
                    if (grid.test(idx)) return false;
                    grid.set(idx);
                }
            }
        }
        return true;
    }
};
