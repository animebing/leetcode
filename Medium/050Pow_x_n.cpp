// based on what I got when i am doing AutoDiff
#include <climits>     // for INT_MIN
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 1.0) return x; // --------------------, not necessary
        if (n > 0) {
            if (n%2 == 0) return myPow(x*x, n/2);
            else return x*myPow(x*x, (n-1)/2);
        }else {  // i forget the case n < 0 first
            if (n == INT_MIN) return myPow(x, -1)*myPow(x, n+1);   // important here 
            else return 1.0/myPow(x, -n);
        }
    }
};

// based on the solution of mingjun, https://discuss.leetcode.com/topic/21837/5-different-choices-when-talk-with-interviewers
// consider the bit representation of n, then get the base, iteratively compute the res
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 1.0) return 1.0;
        double res = 1.0;
        if (n < 0) {
            x = 1/x;   // here to avoid underflow
            res *= x;
            n = -(n+1);
        }
        while (n) {
            if (n&1) res *= x;  // this bit of n is 1, then multiplied by base
            x *= x;    // important here, change the base
            n >>= 1;
        }
        return res;
        
    }
};