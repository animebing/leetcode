// check whether each substring is panlindrom, brute force
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()==0 || s.size()==1) return s;
        string res;
        int max_l = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s.size()-i <= max_l) break;    // ------------------------------------------------------
            for (int j = i+1; j < s.size(); j++) {
                if (j-i+1 <= max_l) continue;  // ------------------------------------------------------
                int t_1 = i;
                int t_2 = j;
                bool flag = true;
                while (t_1 <= t_2) {
                    if (s[t_1] != s[t_2]) { 
                        flag = false;
                        break;
                    }
                    t_1++;
                    t_2--;
                }
                if (flag && j-i+1>max_l) {
                    max_l = j-i+1;
                    res = string(s.begin()+i, s.begin()+j+1);
                }
            }
        }
        if (max_l == 0) res = string(s.begin(), s.begin()+1);
        return res;
    }
};


// expand from center to form panlindrome instead of two edge
int expand(string &s, int left, int right) {
    while (left>=0 && right<s.size()) {
        if (s[left] != s[right]) break;
        left--;
        right++;
    }
    return right-left-1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            int len_1 = expand(s, i, i);  // odd
            int len_2 = expand(s, i, i+1); // even
            int tmp = max(len_1, len_2);
            if (tmp > len) {
                len = tmp;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, len);
    }
};

// dynamic programming, dp[i][j] indicates whether s_i ... s_j is palindromic
// dp[i][i] = true, dp[i][i+1] = s_i == s_j
// dp[i][j] = dp[i+1][j-1] && s_i == s_j (j > i)
// here we have to compute dp[i][j] from large i  
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) dp[i][i] = true;
        for (int i = 0; i < s.size()-1; i++) dp[i][i+1] = (s[i] == s[i+1]);
        int start = 0, len = 0;
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (dp[i][j] == false) dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]);
                if (dp[i][j]) {
                    if (j-i+1>len) {
                        len = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};
// above 2 two solution are based on https://leetcode.com/articles/longest-palindromic-substring/