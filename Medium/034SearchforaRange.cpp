// run bSearch first to see whether the target is in the array, then run bSearch toward left and 
// right direction, until we can't find other target.
// i can't precisely say it is O(n), because i can't figure out that in while loop
int bSearch(vector<int> &nums, int low, int high, int target) {
    while (low <= high) {
        int middle = low + (high-low)/2;
        if (nums[middle] == target) return middle;
        else if(nums[middle] < target) low = middle+1;
        else high = middle-1;
    }
    return -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return vector<int> {-1, -1};
        int idx = bSearch(nums, 0, n-1, target);
        if (idx == -1) return vector<int> {-1, -1};
        int l_idx = idx, r_idx = idx;
        bool l_flag = true, r_flag = true;
        while (1) {
            int tmp;
            if (l_flag) {
                tmp = bSearch(nums, 0, l_idx-1, target);
                if (tmp == -1) l_flag = false;
                else l_idx = tmp;
            }
            if (r_flag) {
                tmp = bSearch(nums, r_idx+1, n-1, target);
                if (tmp == -1) r_flag = false;
                else r_idx = tmp;
            }
            if (!l_flag && !r_flag) break;
        }
        return vector<int> {l_idx, r_idx};
    }
};


// the solution of stellari, https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation
// two binary search to find the left and bound respectively

// the solution of StefanPochmann, https://discuss.leetcode.com/topic/16486/9-11-lines-o-log-n
// algorithm in c++
// eqaul_range, lower_bound, upper_bound
