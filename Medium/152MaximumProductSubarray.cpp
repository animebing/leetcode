// based on the solution of mzchen, https://discuss.leetcode.com/topic/4417/possibly-simplest-solution-with-o-n-time-complexity
// dynamic programing, there are two dp state, one is i_max[i], which represents the maxinum continous subarray product including nums[i]
// i_min[i] is the minimum continuous subarray product including nums[i]
// then what is transfer formula, because it is product here, so when nums[i] is negative, swap(i_max[i-1], i_min[i-1]), then 
// i_max[i] = max(nums[i], nums[i]*i_max[i-1]),     i_min[i] = min(nums[i], nums[i]*i_min[i-1])
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int i_min = res, i_max = res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(i_max, i_min);
            i_max = max(nums[i], nums[i]*i_max);
            i_min = min(nums[i], nums[i]*i_min);
            res = max(res, i_max);
        }
        return res;
    }
};