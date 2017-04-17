// sort first, then find all elements which occur more then n/3, O(nlogn) time complexity, O(1) space complexity
// I can use map, O(n) time, but not O(1) space
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int start = i;
            while (i<nums.size()-1 && nums[i]==nums[i+1]) i++;
            if (i-start+1 > nums.size()/3) res.push_back(nums[i]);
        }
        return res;
    }
};

// there is a solution using Boyer-Moore, I can't understand well, and implement it incorrectly
// https://discuss.leetcode.com/topic/17564/boyer-moore-majority-vote-algorithm-and-my-elaboration