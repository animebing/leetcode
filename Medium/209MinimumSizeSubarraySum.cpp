// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c
// it is the modification of the brute-force solution, find the minimum length starting from each element, then get mininum of all minimums
// optimization is to find what is wasted, then think of whether we can use this part or discard this part
// O(n) method
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, start = 0, min_len = INT_MAX;
        for (int i = 0; i< nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                min_len = min(min_len, i-start+1);
                sum -= nums[start++];
            }
        }
        return min_len==INT_MAX ? 0 : min_len;
    }
};

// there are O(nlogn) method, but i didn't figure it out, https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c
