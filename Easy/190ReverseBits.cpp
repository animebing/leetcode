// use uint32_t to initialize bitset<32>, then tranform bitset<32> to string, 
// then reverse string, use the string to initialize 
// bitset, the  transform bitset to uint32_t
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bitNum(n);
        string strNum = bitNum.to_string();
        reverse(strNum.begin(), strNum.end());
        bitNum = bitset<32>(strNum);
        return (uint32_t) bitNum.to_ulong();
    }
};


// based on the solution of VectorYao
// really awesome solution use bit operation 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
            res = (res<<1) + (n>>i & 1);
        
        return res;
    }
};

// based on the solution of tworuler 
// brand and conquer
// i don't implement it on my own, just paste here as reference
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};