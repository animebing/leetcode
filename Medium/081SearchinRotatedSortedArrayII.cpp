// just like how I did in Search in Rotated Sorted Array I, find the rotate idx, then use binary search, n+log2(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1]) {
                cnt = i+1;
                break;
            }
        }
        int low = 0, high = n; // high is excluded
        while (low < high) { // so here low can be equal to high
            int mid = low+(high-low)/2;
            int idx = (mid+cnt)%n;
            if (nums[idx] == target) return true;
            else if (nums[idx] > target) high = mid;  // ---------------
            else low = mid+1;
        }
        return false;
    }
};

// the same as the 2nd solution in Search in Rotated Sorted Array I, but use pruning to skip duplicates
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            while (low<high && nums[low]==nums[low+1]) low++; 
            while (low<high && nums[high]==nums[high-1]) high--;
            int mid = low+(high-low)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[high]) {
                if (nums[mid]<target && target<=nums[high]) low = mid+1;
                else high = mid-1;
            }else {
                if (target>=nums[low] && target<nums[mid]) high = mid-1;
                else low = mid+1;
            }
        }
        return false;
    }
};