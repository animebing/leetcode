// access the element one by one until the element is not consisten
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int start = 0;
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i==nums.size()-1 || nums[i]+1!=nums[i+1]) {   // at first, i use nums[i+1]-nums[i] > 1, there will be overflow for some cases, 
                if (i == start) res.push_back(to_string(nums[start]));  // so i change to this way
                else res.push_back(to_string(nums[start])+"->"+to_string(nums[i]));
                start = i+1;
            }
        }
        return res;
    }
};


// based on the solution of tanchiyuxx, https://discuss.leetcode.com/topic/17151/accepted-java-solution-easy-to-understand/2
// use while loop to find the range, a little fast than above solution
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> res;
        for (int i = 0; i < nums.size(); i++) {
            int start = i;
            while (i<nums.size()-1 && nums[i]+1==nums[i+1]) i++;
            if (i == start) res.push_back(to_string(nums[start]));
            else res.push_back(to_string(nums[start])+"->"+to_string(nums[i]));
        }
        return res;
    }
};