// based on the solution of tian.xia.568,https://discuss.leetcode.com/topic/17081/three-lines-in-c-with-explanation
// for the prices, if a <= b <= c <= d, then res = d-a = d-c + c-b + b-a
// when a <= b >= c <= d, then res = b-a + d-c
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) res += prices[i] - prices[i-1];
        }
        return res;
    }
};