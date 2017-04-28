// based on the solution of mehran, https://discuss.leetcode.com/topic/25580/two-solutions-with-explanation-o-nlog-n-and-o-n-time-o-1-space-without-changing-the-input-array
// binary search solution, here I want to find the replicate number directly, for a candicate number,compute the number of elements 
// less than or equal to it, if the cnt is less than or equal to it, the replicate number must be behind, otherwise before
// O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int left = 1, right = nums.size()-1;  
        while (left < right) {
            int mid = left + (right-left)/2;
            int cnt = 0;
            for (int v : nums) 
                if (v <= mid) cnt++;
            if (cnt <= mid) left = mid+1;
            else right = mid;
        }
        return left;
    }
};