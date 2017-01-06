class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int base = 1;
        while (1){
            int quo = n / base;
            int rem = n % base;
            if (quo == 1){    // we can say, there must be a base such that the quotient is 1 from the binary representation of n
                if (rem == 0) return true;
                else return false;
            }
            base *=2;
        }
    }
};


// based on the solution of dong.wang.1694
// it is really magic
// n-1 will make all 0 flip to 1, and the first 1 flip to 0(from right to left)
// if the n is the power of 2, then n&(n-1) should be 0, otherwise it is not 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
    }
};