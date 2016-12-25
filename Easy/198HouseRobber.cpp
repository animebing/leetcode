// dynamic programming, two cases: rob the current house or not
// keep two variable, prev_1, the maximum money until the last one, 
// prev_2, the maximum money until penult 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int prev_2 = nums[0], prev_1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++){
            int tmp = max(nums[i]+prev_2, prev_1);
            prev_2 = prev_1;
            prev_1 = tmp;
        }
        return prev_1;
    }
};

// manage the code according to other solutions, the same as above solution
// max in <algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev_1 = 0, prev_2 = 0;
        for (int i = 0; i < n; i++){
            int tmp = max(nums[i]+prev_2, prev_1);
            prev_2 = prev_1;
            prev_1 = tmp;
        }
        return prev_1;
    }
};