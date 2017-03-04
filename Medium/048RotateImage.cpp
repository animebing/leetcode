// based on the solution of justyu, https://discuss.leetcode.com/topic/17645/6-lines-of-code-and-with-o-1-space-in-c
// transpose the matrix first, then reverse each row
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)  // ----------------------------------------
                swap(matrix[i][j], matrix[j][i]);
        }
        for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end()); // --------------------------------
    }
};

// the solution of sazzadleetcode, I can't understand it. https://discuss.leetcode.com/topic/20921/4ms-few-lines-c-code-rotate-image-90-degree-for-o-1-space