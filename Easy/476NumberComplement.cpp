// xor ^ 1 can flip bit
// when num > 0, use num>>1 to stop when leading zero accurs
// use res^ 1<<i to flip the ith bit from right
// when num < 0, use i < 32 to control the loop, because num will never be zero(arithmetic right shift)
class Solution {
public:
    int findComplement(int num) {
        int res = num;
        int i = 0;
        while (num && i < 32) {
            res ^= 1<<i;
            num >>= 1;
            i++;
        }
        return res;
    }
};


// based on the solution of lzl124631x137 and Kenigma, https://discuss.leetcode.com/topic/74627/3-line-c/2
// from here. i know the point is to find the mask which will be all 1 until the first leading 0 from left
class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while (num & mask) mask <<= 1; // 
        return num ^ ~mask;
    }
};


// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/74897/maybe-fewest-operations
// for 8 bit num B, 10000000, then B |= B>1, B |= B>>2, B |= B>>4 will make all bits of B 1, so for 32 bit num,
// do similar thing, we will make num all 1 from the first 1 in num from left. 
class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        mask |= mask>>1;
        mask |= mask>>2;
        mask |= mask>>4;
        mask |= mask>>8;
        mask |= mask>>16;
        return num ^ mask;
    }
};

