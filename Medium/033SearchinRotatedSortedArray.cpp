// first find the place where the array is rotated, then use binary searth
// O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int r = 0;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1]) {
                r = i+1;
                break;
            }
        }
        
        int low = 0, high = n-1;
        
        while (low <= high) {
            int middle = low + (high-low)/2;
            int idx = (middle+r)%n;
            
            if (nums[idx] == target) return idx;
            else if (nums[idx] > target) high = middle-1;
            else low = middle+1;
        }
        
        return -1;
    }
};


// there are some solution to use the fact that the array partly sorted, so O(logn), but i can't understand their solution
// i will see these solution later 

// use binary search directly, but consider different situations when nums[mid] != target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2; // mid = low&high + (low^high)>>1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[high]) {
                if (target>nums[mid] && target<=nums[high]) low = mid+1;
                else high = mid-1;
            }else {
                if (target>=nums[low] && target<nums[mid]) high = mid-1;
                else low = mid+1;
            }
        }
        return -1;
    }
};