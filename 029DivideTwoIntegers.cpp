// method
//     1 find the max quotient i that is the power of 2 such that divisor * i < dividend, then dividend -= divisor * i
//     2 repeat step 1 until dividend < divisor
// INT_MAX: 2147483647 INT_MIN: -2147483648
// the sign of the quotient: if dividend and divisor have the same sign, then quotient is positive, otherwise negative
// special case: INT_MIN / 1 = INT_MIN  INT_MIN / -1 = INT_MAX
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        bool sign = (dividend<0)^(divisor<0) ? true : false;
        long a = dividend, b = divisor;
        a = abs(a);
        b = abs(b);
        long quotient = 0;
        while (a >= b){
            long tmp = b;
            long mul = 1;
            while (tmp<<1 <= a){
                tmp <<= 1;
                mul <<= 1;
            }
            quotient += mul;
            a -= tmp;
        }
        if (quotient > INT_MAX){
            if (sign) return INT_MIN;
            else return INT_MAX; 
        }
        return (sign) ? -quotient : quotient; 
    }
};
// in the above code, long type is used, they are all reasonble
//    1 long a, b to make the abs(INT_MIN) meaningful, otherwise the abs(INT_MIN) == INT_MIN, I have tested it.
//    2 long tmp to avoid the left shift operation causing overflow
//    3 long quotient, mul to avoid overflow in special case