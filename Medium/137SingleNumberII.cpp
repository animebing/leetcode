// naive solution, count the occurrence of each element, then find that one
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int v:nums) cnt[v]++;
        for (auto p:cnt) {
            if (p.second == 1) return p.first;
        }
    }
};


// based on the solution on http://www.cnblogs.com/higerzhang/p/4159330.html
// for 32 bits, for each element, & with 1<<i, then we can count how many elements which have 1 in this bit
// it the number can be divided by 3, then there is no 1 in this bit for the elements appearing only once
// so here 3 can be k
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0, bit = 1<<i;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & bit) cnt++;
            }
            if (cnt%3) ans |= bit;
        }
        return ans;
    }
};


// there is still another method with same idea as above, but different implementation, I can't understand it
// http://www.cnblogs.com/higerzhang/p/4159330.html
// https://discuss.leetcode.com/topic/2031/challenge-me-thx 