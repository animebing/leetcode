// 1. compute the binary representation
// 2. compute every 4 bits from left to right
class Solution {
public:
    string toHex(int num) {
        int b[32] = {0};
        for (int i = 0; i < 32; i++) b[31-i] = (num >> i) & 1;
        string res;
        for (int i = 0; i < 32; i += 4) {
            int tmp = b[i]*8 + b[i+1]*4 + b[i+2]*2 + b[i+3];
            if (tmp == 0 && res.size()==0) continue;   // cattion here
            if (tmp-9 > 0) res += tmp-10 + 'a';
            else res += tmp + '0';
        }
        return res.empty() ? "0" : res; // caution here
    }
};


// based on the solution of palindrome018
// right shift every 4 bits, not one by one
// pay attention to the difference of arithmetic and logic shift and the implementation of shift in compiler
// here is the implementation in visual c++ https://msdn.microsoft.com/zh-cn/library/336xbhcz.aspx
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hex = "0123456789abcdef";
        string res;
        int cnt = 0;
        while (num && cnt < 8) {
            res = hex[num&0xf] + res;
            num >>= 4;
            cnt++;
        }
        return res;
    }
};