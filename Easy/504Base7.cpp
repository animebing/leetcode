// base 7, divide 7 repeatedly until the quotient is zero, the early remainder is in the least significant bit
#include <algorithm>  // here for reverse
string helper(int num) {
    string res;
    while (1) {
        int tmp = num % 7;
        res.push_back(tmp+'0'); // no matter what, the remaider should be included, here it is from least to most important bit
        num /= 7;
        if (num == 0) break;
    }
    reverse(res.begin(), res.end());
    return res;
}
class Solution {
public:
    string convertToBase7(int num) {
        if (num >= 0) return helper(num);
        else return "-"+helper(-num);
    }
};


// based on the solution of kevin36, https://discuss.leetcode.com/topic/78938/c-solution
// recursion 
#include <string>   // here for to_string
class Solution {
public:
    string convertToBase7(int num) {
        string str;
        if (num < 0) return "-" + convertToBase7(-num);
        while (1) {
            int rem = num % 7;
            str = to_string(rem) + str;
            num /= 7;
            if (num == 0) break;
        }
        return str;
    }
};