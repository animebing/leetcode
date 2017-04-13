// Binary Search Tree
// based on the solution of lchen77, https://discuss.leetcode.com/topic/18453/c-using-set-less-10-lines-with-simple-explanation
// first find the window meeting that absolute difference between i and j is at most k, then check whether there are two elements
// in the window that meets absolute difference between nums[i] and nums[j] is at most t
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k<=0 || t < 0) return false;
        set<long> window;  // element in set is orderer increasingly
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > k)  window.erase((long)nums[i-k-1]);  // keep window size at most k
            // check if we insert nums[i] to the set, whether we can find x in the set such that |nums[i]-x| <= t
            // which means nums[i]-x >= -t or nums[i]-x <= t, first we consider nums[i]-x <= t  ---> x >= nums[i]-t
            auto pos = window.lower_bound((long)nums[i]-t);
            if (pos!=window.end() && (long)nums[i]-*pos>=-t) // the x also meets nums[i]-x>= -t, then |x-nums[i]| <= t, bingo, find one
                return true;
            window.insert((long)nums[i]);   // we can't find x in current window, so move forward the window
        }
        return false;
    }
};