// naive solution, dp, m2sum[i][j] is the sum from [0, 0] to [i, j]
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return; 
        m2sum = vector<vector<int>>(m, vector<int>(n, 0));
        m2sum[0][0] = matrix[0][0];
        for (int col = 1; col < n; col++) m2sum[0][col] = matrix[0][col]+m2sum[0][col-1];
        for (int row = 1; row < m; row++) m2sum[row][0] = matrix[row][0] + m2sum[row-1][0];
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                m2sum[row][col] = m2sum[row][col-1]+m2sum[row-1][col]-m2sum[row-1][col-1]+matrix[row][col]; // -------
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = m2sum[row2][col2], sub = 0;
        if (row1-1>=0 && col1-1>=0) sum += m2sum[row1-1][col1-1];
        if (row1-1>=0) sub += m2sum[row1-1][col2];
        if (col1-1>=0) sub += m2sum[row2][col1-1];
        return sum - sub; // ---------
    }
private:
    vector<vector<int>> m2sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
