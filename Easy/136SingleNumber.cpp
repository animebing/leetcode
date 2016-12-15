// Based on the solution of xuhua.alex 
// A^B^A = B 0^A = A A^A = 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto n:nums) res ^= n;
        return res;
    }
};