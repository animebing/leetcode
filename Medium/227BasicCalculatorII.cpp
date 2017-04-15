// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/16807/17-lines-c-easy-20-ms
// 1. add one '+' in the front of and at the back of the original string
// 2. use term, which means a result between '+'/'-' operation
// 3 stringstream will ignore the whitespace in the front of stream
class Solution {
public:
    int calculate(string s) {
        string new_s = '+'+s+'+';
        istringstream  sstream(new_s);
        int total = 0, term = 0;
        char op;
        while (sstream >> op) {
            if (op=='+' || op=='-') {
                total += term;   // negative info have been embedded in term
                sstream >> term;
                if (op == '-') term = -term;  // embed negative info to term
            } else {
                int n;
                sstream >> n;
                if (op == '*') term *= n;
                else term /= n;
            }
        }
        return total;
    }
};