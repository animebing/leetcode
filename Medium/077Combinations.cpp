// standard backtracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n<=0 || k<=0) return {};
        vector<vector<int>> res;
        vector<int> com;
        helper(res, com, n, 1, k);
        return res;
    }
private:
    void helper(vector<vector<int>> &res, vector<int> &com, int n, int start, int left) { // left: how many numbers we need 
        if (left == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i <= n; i++) {
            if (n-i+1 < left) break; // pruning, early stop
            com.push_back(i);
            helper(res, com, n, i+1, left-1);
            com.pop_back();
        }
    }
};


// based on the solution of hengyi, https://discuss.leetcode.com/topic/26689/short-iterative-c-answer-8ms
// when n = 5, k = 3, [1 2 3] [1 2 4] [1 2 5] [1 3 4] [1 3 5] [1 4 5] [2 3 4] [2 3 5] [2 4 5] [3 4 5]
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n<=0 || k<=0) return {};
        vector<vector<int>> res;
        vector<int> com(k, 0);
        int i = 0;
        while (i >= 0) {
            com[i]++;
            if (com[i] > n) i--;
            else if (i == k-1) res.push_back(com);
            else {
                i++;
                com[i] = com[i-1];
            }
        }
        return res;
    }
};