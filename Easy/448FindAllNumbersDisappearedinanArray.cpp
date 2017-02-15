// naive solution with O(n) extra space, compute the number of occurrence of each number, then the number with occurrence == 0
// is disappearing
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res, cnt(nums.size(), 0);
        for (int v:nums) cnt[v-1]++;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0) res.push_back(i+1);
        }
        return res;
    }
};


// based on the solution of RushRab, https://discuss.leetcode.com/topic/65944/c-solution-o-1-space
// this solution is really smart to use sign to indicate why a number appear
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = abs(nums[i])-1;   // tmp is the position of nums[i]
            // nums[tmp] = -1*abs(nums[tmp]);  // this is more straightforward
            nums[tmp] = nums[tmp]>0 ? -nums[tmp] : nums[tmp];    // negate the number at position tmp to indicate the nums[i] appear
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) res.push_back(i+1);  // if nums[i] is positive, it indicates that i+1 findDisappearedNumbers
        
        return res;
    }
};