// like transform "base 26" number into decimal number
// from least significant bit to most significant bit
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, n = s.size();
        int base = 1;
        for (int i = 0; i < n; i++){
            res += (s[n-i-1]-'A'+1)*base;
            base *= 26;
        }
        return res;
    }
};

// from most significant bit to least significant bit
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, n = s.size();
        int base = 26;
        for (int i = 0; i < n; i++) res = res*base + s[i]-'A'+1;
        return res;
    }
};