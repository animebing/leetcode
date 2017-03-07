// based on the solution of alexander7 and Ximin.Z, https://discuss.leetcode.com/topic/4911/linear-and-simple-solution-in-c/9
// update the maximum place you can reach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0; 
        for (int i = 0; i < n; i++) {
            if (i > reach) return false;  // false checking 
            reach = max(reach, i+nums[i]);  // update reach
            if (reach >= n-1) return true;  // early checking
        }
    }
};