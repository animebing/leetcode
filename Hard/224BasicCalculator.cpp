// there only '+', '-', ' ', '(', ')' and numbers, then calculate the expression, the point is to discard the '(', then 
// get the right sign for the following number
// based on the solution of ironhead.chuang, https://discuss.leetcode.com/topic/15775/simple-c-in-24-ms
class Solution {
public:
    int calculate(string s) {
        stack<int> signs;  // store the outer sign for each "()" pair
        signs.push(1); // assuming there is always a pair of "()" surrounding the expression
        int sign = 1;  // the sign before number or '('
        int total = 0;
        int num = 0;
        for (char c : s) {
            if (c>='0' && c<='9') num = num*10+c-'0';
            if (c=='+' || c=='-') {
                total += num*sign*signs.top();
                num = 0;
                if (c == '+') sign = 1;
                else sign = -1;
            }
            if (c == '(') {
                signs.push(signs.top()*sign);
                sign = 1;
            }
            if (c == ')') {
                total += num*sign*signs.top();
                signs.pop();
                num = 0;
                sign = 1;
            }
        }
        if (num) total += num*sign;  // num == 0 means there is ')' at last, or there is a number at last
        return total;                // total += num*sign*signs.top(); there is only one element in signs, which is 1 
    }
};