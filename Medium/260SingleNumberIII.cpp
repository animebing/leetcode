// based the solution of zhiqing_xiao, https://discuss.leetcode.com/topic/21605/accepted-c-java-o-n-time-o-1-space-easy-solution-with-detail-explanations
// first xor all elements, then we can get the xor of the two different elements, because they are different, so there must one bit
// is 1, then according this bit, we can divide all elements into two groups, one group for this bit being 0, the other group for 
// this bit is 1, then we can get one element in each group
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for (int v : nums) tmp ^= v;
        int diff = tmp & (-tmp);  // I want to find the right most bit 1, here I use a + (-a) = 0 to find that bit
        vector<int> res(2, 0);
        for (int v : nums) {
            if (v & diff) res[0] ^= v;  // this bit is 1
            else res[1] ^= v;   // this bit is 0
        }
        return res;
    }
};



// based the solution of jianchao.li.fighter and StefanPochmann
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for (int v : nums) tmp ^= v;
        int diff = tmp & ~(tmp-1);  // use tmp-1 we can find the right most bit 1
        int res = 0;
        for (int v : nums) 
            if (v & diff) res ^= v;  // find one element first 
        return {res, res^tmp};  // xor to get the other one
    }
};