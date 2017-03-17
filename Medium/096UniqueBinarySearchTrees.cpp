// based on the solution of liaison, https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
// divide and conquer
class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> G(n+1, 0);
        G[0] = G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};


// I have tried the same recursion version as Unique Binary Search Trees II, but time limit exceeded when
// n >= 18, that is because there will be something are repeatedly computed using recursion
// the number of all trees only depends on the number of elements, not what numbers they are
// to compute the number is different from to comstruct all trees, because to compute the number, I don't need to concern
// which node it is, so use the same way, there will be some redundant computation
class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        return helper(1, n);
    }
    int helper(int start, int end) {
        if (start > end) return 1;
        int res = 0;
        for (int i = start; i <=  end; i++) {  // I use the way to construct the tree to compute the number
            int left = helper(start, i-1);  
            int right = helper(i+1, end);
            res += left * right;
        }
    }
    return res;
}