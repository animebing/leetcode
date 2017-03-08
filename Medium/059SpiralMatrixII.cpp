// the same as Spiral Matrix I, one round by one round, define upper, bottom, left and right border and check them
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return {};
        vector<vector<int>> res(n, vector<int>(n));
        int u = 0, b = n-1, l = 0, r = n-1, k = 1;
        while (1) {
            for (int col = l; col <= r; col++) res[u][col] = k++;
            if (++u > b) break;
            for (int row = u; row <= b; row++) res[row][r] = k++;
            if (--r < l) break;
            for (int col = r; col >= l; col--) res[b][col] = k++;
            if (--b < u) break;
            for (int row = b; row >= u; row--) res[row][l] = k++;
            if (++l > r) break;
        }
        return res;
    }
};


// based on the python solution of StefanPochmann, https://discuss.leetcode.com/topic/19130/4-9-lines-python-solutions
// use di, dj to represent the increment in row and col, when next element is visited, then change direction 
// by change the value of di and dj, which is point of this method
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return {};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, di = 0, dj = 1;
        for (int k = 0; k < n*n; k++) {
            res[i][j] = k+1;
            if (res[(i+di+n)%n][(j+dj+n)%n]) {   // in python -1%n == n-1, but in c++, -1%n = -1
                int tmp = di;                    // so I have to change (i+di)%3 in the original solution to (i+di+n)%3
                di = dj;
                dj = -tmp;
            }
            i += di;
            j += dj;
        }
        return res;
    }
};