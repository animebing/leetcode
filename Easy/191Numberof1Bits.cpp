// use bitset count method
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bitNum(n);
        return (int)bitNum.count();
    }
};

// use bit operation
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++)
            res += (n>>i & 1);
        return res;
    }
};


// Based on the solution of makuiyu and explanation of salgat
// when n subtracts 1, it will borrow from 0 until 1 appears, so every time we can get one 1 until n is zero
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while (n){
            n &= n-1;
            cnt++;
        }
        return cnt;
    }
};