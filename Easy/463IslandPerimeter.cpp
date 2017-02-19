// for each land cell, compute how many water cell around it, then sum them to get the perimeter
// if I do this in the original grid, I have to deal with the margin, to avoid the check whether a cell is in margin
// i create a new grid with padding 1 in the original grid, which makes the check much easier
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> new_grid(row+2, vector<int>(col+2, 0));  // 
        for (int i = 1; i < row+1; i++) {
            for (int j = 1; j < col+1; j++) {
                new_grid[i][j] = grid[i-1][j-1];
            }
        }
        int res = 0;
        for (int i = 1; i < row+1; i++) {
            for (int j = 1; j < col+1; j++) {
                if (new_grid[i][j])  // whether the cell is land
                    res += 4-(new_grid[i][j-1]+new_grid[i][j+1]+new_grid[i-1][j]+new_grid[i+1][j]);   // water around the land
            }
        }
        return res;
    }
};


// based on the solution of beckswu, https://discuss.leetcode.com/topic/68845/c-solution-with-explanation
// first count how many lands are, which is cnt, without considering of the surrounding cell, the total perimetr are 4 times cnt,
// then count how many edge that connects with two lands, which is repeat, then we need to deduct 2 times repeat from total perimeter 
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0, repeat = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]==1) {
                    cnt++;
                    if (i!=0 && grid[i-1][j]==1) repeat++; // horizontal edge
                    if (j!=0 && grid[i][j-1]==1) repeat++; // vertical edge
                }
            }
        }
        return 4*cnt-2*repeat;
    }
};

// based on the solution sodhanipranav, https://discuss.leetcode.com/topic/68824/c-easy-to-understand-find-edges
// compute the horizontal and vertical edge respectively
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        // horizontal edge
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col-1; j++) 
                res += abs(grid[i][j]-grid[i][j+1]);  // now and right
            res += grid[i][0]+grid[i][col-1];  // most left and most right corner of each row
        }
        // vertical edge
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row-1; i++)
                res += abs(grid[i][j]-grid[i+1][j]);  // now and down
            res += grid[0][j]+grid[row-1][j]; // most up and most down corner of each col 
        }
        return res;
    }
};