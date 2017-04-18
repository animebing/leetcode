// based on the solution of lycjava3, https://discuss.leetcode.com/topic/18864/simple-java-solution-in-o-n-without-extra-space
// two pass, the first is to compute the product of previous elements, the second is to compute the product of latter elements, nice solution 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> res(nums.size(), 0);
        res[0] = 1;  // -------------------------------
        for (int i = 1; i < nums.size(); i++) res[i] = res[i-1]*nums[i-1];  // ----------
        int right = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};


// for me, i don't know how to combine all elements without division, the naive solution can be done in O(n^2)