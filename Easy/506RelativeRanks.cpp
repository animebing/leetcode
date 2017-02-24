// make a map which connects the score and index, in default, then contents in map is orderd by keys' value, increasing
// here i change the compare function map to make the keys' value decreasing
#include <map> // for map;
#include <vector> // for vector
#include <string> // for string
#include <functional> // for greater or less, we also can use function points to initialize a map
// http://www.cplusplus.com/reference/map/map/map/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty()) return vector<string> {};
        map<int, int, greater<int>> num2idx;   // in default, map<int, int, less<int> >, here greater and less are function template
        for (int i = 0; i < nums.size(); i++) {
            num2idx[nums[i]] = i;
        }
        vector<string> res(nums.size(), "");
        int i = 0;
        for (auto p:num2idx){
            string tmp;
            if (i == 0) tmp = "Gold Medal";
            else if (i == 1) tmp = "Silver Medal";
            else if (i == 2) tmp = "Bronze Medal";
            else tmp = to_string(i+1);
            res[p.second] = tmp;
            i++;
        }
        return res;
    }
};

# based on the function of StefanPochmann, https://discuss.leetcode.com/topic/77943/python-solution
# usage of map
class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sort = sorted(nums)[::-1]
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(str, range(4, len(nums)+1))
        return map(dict(zip(sort, rank)).get, nums)

// one solution use another vector to record the idx, then sort based on these two vectors, now i don't know why it can works in sort algorithm
// https://discuss.leetcode.com/topic/77869/simple-sorting-o-n-log-n-solution

// some other solution uses priority_queue to solve it, i don't know about priority queue
// https://discuss.leetcode.com/topic/77912/c-easy-to-understand