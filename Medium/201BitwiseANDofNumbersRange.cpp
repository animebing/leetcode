// based on the solution of zwangbo, https://discuss.leetcode.com/topic/12133/bit-operation-solution-java
// [m, n] is consistent, if m!=n, there are even and odd numbers, then the last bit of and operation will be zero
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) return 0;
        int factor = 1;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            factor <<= 1;
        }
        return m*factor;
    }
};

// same idea, but recursive implementation
// based on the solution of applewolf, https://discuss.leetcode.com/topic/13508/one-line-c-solution/2
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) return 0;
        return m!=n ? (rangeBitwiseAnd(m>>1, n>>1)<<1) : m;
    }
};