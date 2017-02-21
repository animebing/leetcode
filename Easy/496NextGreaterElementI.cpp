// at first, i don't understand what it saids, then by google, i got it
// for each number x in findNums, we need to know its position in nums, then 
// find the first number greater than x in the right of that position in nums 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res(findNums.size(), -1);
        for (int i = 0; i < findNums.size(); i++) {
            int j;
            for (j = 0; j < nums.size(); j++) {
                if (nums[j] == findNums[i]) break;
            }
            j++;
            for (; j < nums.size(); j++)
                if (nums[j] > findNums[i]) {
                    res[i] = nums[j];
                    break;
                }
        }
        return res;
    }
};


// based on the solution of lzl124631x, https://discuss.leetcode.com/topic/78397/c-stack-unordered_map
// use a stack to store the elements which don't find the next greater number in nums, an unordered_map
// to store the elements which find next greater elements
// in this method, we have to construct the map first no matter what findNums are, so when size of findNums 
// is small, i think it is a little wasteful to construct this first
// but this solution is really cool using stack and map
#include <vector>
#include <stack>
#include <unordered_map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int v:nums) {
            while (s.size() && s.top()<v) {
                m[s.top()] = v;
                s.pop();
            }
            s.push(v);
        }
        vector<int> res;
        for (int v:findNums) res.push_back(m.count(v) ? m[v] : -1); 
        return res;
    }
};


// i find an interesting python syntax, generator expression
// the solution of StefanPochmann, https://discuss.leetcode.com/topic/77959/meh-1000-is-small
def nextGreaterElement(self, findNums, nums):
    return [next((y for y in nums[nums.index(x):] if y > x), -1) for x in findNums]

// (y for y in nums[nums.index(x):] if y > x) is a generator expression
// next, index