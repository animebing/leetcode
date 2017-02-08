// sort two strings first, then compare letter one by one until a different letter occurs
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i]) return t[i];
        return t[s.size()];
    }
};

// based on the solution of yanchao_hust 
// clever solution using xor manipulation just like https://leetcode.com/problems/single-number/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto c:s) res ^= c;
        for (auto c:t) res ^= c;
        return res;
    }
};