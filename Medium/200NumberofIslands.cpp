// at first, i don't know what to do, when i see "Show Tags", I get "BFS", "DFS", then I realize, if I start from one land, then 
// dfs to find all surrounding lands, then i can find one island, but i need to record which land i have visited, so I change the land
// i have visited to '2'. so when I find a new '1' in the grid, I find a new island. at last, I recover all '2' to '1'; 
/*
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
// use this to form new point
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    spread(grid, i, j, m, n);
                }
            }
        }
        for (int i = m; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '2') grid[i][j] = '1';
            }
        }
        return res;
    }
private: 
    void spread(vector<vector<char>> &grid, int i, int j, int m, int n) {
        grid[i][j] = '2';
        if (i-1>=0 && grid[i-1][j]=='1') spread(grid, i-1, j, m, n);
        if (j+1<n && grid[i][j+1]=='1') spread(grid, i, j+1, m, n);
        if (i+1<m && grid[i+1][j]=='1') spread(grid, i+1, j, m, n);
        if (j-1>=0 && grid[i][j-1]=='1') spread(grid, i, j-1, m, n);
    }
};