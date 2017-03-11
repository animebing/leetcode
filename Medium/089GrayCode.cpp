// gray code, a binary numeral system where two successive binary number only differ in one bit
// get it recursively, when the gray code of n bits is computed, for n+1 bits, it can be computed by two parts, the first part
// is the same as n bits, the second part is the reverse of n bits with a adding 1 in the most left, refer to 
// https://en.wikipedia.org/wiki/Gray_code#Constructing_an_n-bit_Gray_code
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0) return {};
        vector<int> res {0};
        int base = 1;
        for (int i = 0; i < n; i++) {
            int n = res.size();
            vector<int> tmp(n*2);
            for (int j = 0; j < n; j++) tmp[j] = res[j];
            for (int j = 0; j < n; j++) tmp[j+n] = res[n-1-j] + base;
            res = tmp;
            base *= 2;
        }
        return res;
    }
};

// based on the solution of scorpionsky, https://discuss.leetcode.com/topic/1011/what-is-the-best-solution-for-gray-code-problem-no-extra-space-used-and-no-recursion
// use less space, for the first part is unchanged, so just change the following part and push_back to the original one
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0) return {};
        vector<int> res {0};
        for (int i = 0; i < n; i++) {
            int n = res.size();
            while (n) {
                n--;
                res.push_back(res[n]+(1<<i));
            }
        }
        return res;
    }
};


// based on the solution of zhaotianzju, https://discuss.leetcode.com/topic/23078/4-lines-c-code
// convert binary code to gray code, https://en.wikipedia.org/wiki/Gray_code#Converting_to_and_from_Gray_code
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0) return {};
        vector<int> res(1<<n);  // ------------------
        for (int i = 0; i < (1<<n); i++) {
            res[i] = i ^ (i>>1);  // convert binary code to gray code
        }
        return res;
    }
};