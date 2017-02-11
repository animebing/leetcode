// naive solution, compute how many times a letter appears, if it appears even times, add directly
// or add odd times subtracted by 1
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for (auto c:s) cnt[c]++;
        int res = 0;
        bool flag = false;
        for (auto p:cnt) {
            if (p.second%2 == 0)  res += p.second;
            else {
                if (p.second/2 != 0) res += p.second-1;
                if (!flag) {
                    res++;
                    flag = !flag;
                }
            }
        }
        return  res;
    }
};

// based on the solution of StefanPochmann
// count how many letters which appear odd times and there is only one which can be left
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128, 0);
        for (auto c:s) cnt[c]++;
        int odds = 0;
        for (auto c:cnt) odds += c&1;
        return s.size()-odds+(odds>0);
    }
};

// based on the solution of vesion 
// checking res for whether we already used an odd one
// almost the same idea as me, but shorter and concise implementation
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128, 0);
        for (auto c:s) cnt[c]++;
        int res = 0;
        for (auto c:cnt) res += c%2 ? (res%2?c-1:c) : c;   // attention here, res += c & ~(res & 1)
        return res;
    }
};