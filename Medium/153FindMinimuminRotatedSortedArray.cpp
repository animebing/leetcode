// naive solution, find the first element nums[i] such that nums[i] > nums[i+1], then nums[i+1] is the minimum element
// or nums[0] is minumum element
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) return nums[i+1];
        }
        return nums[0];
    }
};


// based on the solution of changhaz, https://discuss.leetcode.com/topic/4100/compact-and-clean-c-solution
// use binary search, 1: if nums[left] < nums[right], then nums[left] is the minimum element, if not 
// 1: if nums[mid] >= nums[left], then mid is in the left part, so left = mid+1, otherwise, the mid is in the 
// right part, then right = mid, when the search is over, then nums[left] or nums[right] is the minimum
// in terms of time, this method is not faster than above naive one
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];
            int mid = left + (right-left)/2;
            if (nums[mid] >= nums[left]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }
};