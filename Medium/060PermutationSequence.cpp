// based on the solution of Adeath, https://discuss.leetcode.com/topic/5081/an-iterative-solution-for-reference 
// easy to think, a little difficult to implement
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n<=0 || k<=0) return "";
        vector<int> factor(n), nums(n);
        factor[0] = 1;
        for (int i = 1; i < n; i++) factor[i] = i*factor[i-1];    // maybe string nums = "123456789";
        for (int i = 0; i < n; i++) nums[i] = i+1;
        string res;
        k--; // ------------------ simplify checking
        for (int i = n-1; i >= 0; i--) {
            int idx = k/factor[i];  // which number to start with 
            res.push_back(nums[idx]+'0');
            nums.erase(nums.begin()+idx);  // erase the num
            k %= factor[i]; // --------------------------------
        }
        return res;
    }
};