// based on the solution of ran3, https://discuss.leetcode.com/topic/8018/my-java-solution-to-share
// at first, I convert all numbers to string, but i don't know how to define one string is larger than the other one
// solution below gives correct definition, for number string a and b, when a+b > b+a, then a is larger than b
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) return "";
        vector<string> num2string(nums.size());
        for (int i = 0; i < nums.size(); i++) num2string[i] = to_string(nums[i]);
        sort(num2string.begin(), num2string.end(), [](string &a, string &b){return a+b>b+a;});
        string res = "";
        for (int i = 0; i < nums.size(); i++) res += num2string[i];
        int idx = 0;
        while (idx<res.size() && res[idx] == '0') idx++;
        if (idx == res.size()) return "0";
        else return res.substr(idx);
    }
};