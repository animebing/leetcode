// find peak with assumption that nums[-1] = nums[n] = -infinite
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[0] > nums[1]) return i;
            } else if (i == nums.size()-1) {
                if (nums[i] > nums[i-1]) return i;
            } else if (nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
        }
    }
};


// based on the solution of gangan, https://discuss.leetcode.com/topic/5724/find-the-maximum-by-binary-search-recursion-and-iteration
// using this method, i can find the first peak
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) return i-1;
        }
        return nums.size()-1;
    }
};


// based on the solution of gangan, https://discuss.leetcode.com/topic/5724/find-the-maximum-by-binary-search-recursion-and-iteration
// using this method, you can ensure that the peak is the first one
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = low + (high-low)/2;
            int mid_1 = mid+1;
            if (nums[mid] < nums[mid_1]) low = mid_1;
            else high = mid;
        }
        return low;
    }
};