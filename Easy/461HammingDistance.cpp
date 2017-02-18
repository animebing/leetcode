// use integer to initialize bitset, then compare bit one by one
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> bit_x(x);
        bitset<32> bit_y(y);
        int res = 0;
        for (int i = 0; i < 32; i++)
            if (bit_x[i] != bit_y[i]) res++;
        
        return res;
    }
};

// get the bit of x and y one by one,then compare
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x || y) {    // i like this condition
            int tmp_x = x&1, tmp_y = y&1; // get the bit 
            if (tmp_x != tmp_y) res++;
            x >>= 1;  
            y >>= 1;
        }
        return res;
    }
};

// based on the solution of pengr7, https://discuss.leetcode.com/topic/72236/my-c-solution-using-bit-manipulation
// clever solution
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        x = x^y;   // then we need to compute how many 1 in x
        while (x) {
            res++;
            x &= x-1;  // cancel one 1 in x
        }
        return res;
    }
};

// based on the solution of pengr7
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> bit_1(x^y);
        return bit_1.count();  // use bitset<32>.count() to compute how many 1 in x^y
    }
};