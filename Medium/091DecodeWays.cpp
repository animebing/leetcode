// based on the solution of shichaotan, https://discuss.leetcode.com/topic/7025/a-concise-dp-solution
class Solution {
public:
    int numDecodings(string s) {
        if (s.size()==0 || s[0]=='0') return 0; // when the first letter is '0' return 0
        int f_1 = 1, f_2 = 1;
        for (int i = 1; i < s.size(); i++) {
            int f = 0;
            if (s[i] != '0') f += f_1; // when s[i] == '0', these letter can't decoded alone
            if ((s[i-1]=='2' && s[i]<='6') || s[i-1]=='1') f += f_2;  // s[i-1] and s[i] can be decoded together
            if (f == 0) return 0;  // no way to decode
            f_2 = f_1;
            f_1 = f;
        }
        return f_1;
    }
};