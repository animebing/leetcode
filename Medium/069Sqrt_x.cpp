// based on interger square root in https://en.wikipedia.org/wiki/Integer_square_root
// using newton method, but when x+1 is perfect square, using abs(cur-prev) will not converge
// so here I add prev*prev > x checking
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        long prev = x;
        while (prev*prev > x) {
            long cur = (prev+x/prev)/2;
            if (abs(cur-prev) < 1) return cur;
            prev = cur;
        }
        return prev;
    }
};

// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/24532/3-4-short-lines-integer-newton-every-language
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        long cur = x;
        while (cur*cur > x) cur = (cur+x/cur)/2;
        return cur;
    }
};