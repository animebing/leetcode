// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/14504/9-lines-0ms-o-1-space-c-solution
// house 0 and n-1 can't be robbed together, so we divide the case into two cases, 1: n-1 is not robbed, then robber(0, n-1)
// 2: 0 is not robbed, then robber(1, n-1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
private:
    int robber(vector<int> nums, int low, int high) {
        int pre_2 = 0, pre_1 = 0;
        for (int i = low; i <= high; i++) {
            int tmp = max(nums[i]+pre_2, pre_1);
            pre_2 = pre_1;
            pre_1 = tmp;
        }
        return pre_1;
    }
};