// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c
// it is the modification of the brute-force solution, find the minimum length starting from each element, then get mininum of all minimums
// optimization is to find what is wasted, then think of whether we can use this part or discard this part
// O(n) method
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, start = 0, min_len = INT_MAX;
        for (int i = 0; i< nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                min_len = min(min_len, i-start+1);
                sum -= nums[start++];
            }
        }
        return min_len==INT_MAX ? 0 : min_len;
    }
};

// there are O(nlogn) method, but i didn't figure it out, https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c
// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c
// it is the modification of the brute-force solution, find the minimum length starting from each element, then get mininum of all minimums
// first get the accumulation sum, then each sums[i], if sums[i] >= s, then find the upper bound idx of sums[i]-s in [i, i], then i-idx 
// is the least length of subarray ending with nums[i-1] and sum of the subarray is larger than or equal to s.
// so this mothod is to find the minimum length ending with nums[i-1], however above solution is to find the minimum lenght starting with nums[i] 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sums(nums.size()+1, 0);
        int min_len = INT_MAX;
        for (int i = 1; i < sums.size(); i++) sums[i] = nums[i-1]+sums[i-1];
        for (int i = 1; i < sums.size(); i++) {
            if (sums[i] >= s) {
                int tmp_idx = upper_bound(sums, 1, i, sums[i]-s);  // int tmp_idx = lower_bound(sums, 1, i, sums[i]-s+1);
                min_len = min(min_len, i-tmp_idx+1);               // upper_bound(value) = lower_bound(vaule+1);z
            }
        }
        return min_len==INT_MAX ? 0 : min_len;
    }
private:
    int upper_bound(vector<int> &nums, int left, int right, int value) {  // upper_bound is the first element who is larger than it 
        while (left < right) {                                           // lower_bound is the first element who is larger than or equal to it
            int mid = left + (right-left)/2;
            if (value >= nums[mid]) left = mid+1;  
            else right = mid; // 
        } // when the loop is over, left must be equal to right
        return nums[left] > value ? left : -1;  // nums[right] > value ? right : -1; // -1 means all elements in [left, right] is smaller than value
    }
    int lower_bound(vector<int> &nums, int left, int right, int value) {
        while (left < right) {
            int mid = left + (right-left)/2;
            if (value > nums[mid]) left = mid + 1;
            else right = mid;
        }
        return nums[left] >= vaule ? left : -1;
    }
};

