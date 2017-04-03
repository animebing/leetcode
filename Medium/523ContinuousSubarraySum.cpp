// based on the solution of compton_scatter, https://discuss.leetcode.com/topic/80793/java-o-n-time-o-k-space
// get the accumulative sum and sum mod k, if the remaider has existed before, so we can get a subarray 
// whose sum is n*k, and if length is larger than 2, then we get the desired subarray, or continue.
// corner case, k is 0 and the sum is n*k
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rem2idx = {{0, -1}};   // corner case
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k) sum %= k;
            if (rem2idx.count(sum)) {
                if (i-rem2idx[sum] > 1) return true;
            } else rem2idx[sum] = i;
        }
        return false;
    }
};