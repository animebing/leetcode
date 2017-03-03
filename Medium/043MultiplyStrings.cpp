// based on the solution of ChiangKaiShrek, https://discuss.leetcode.com/topic/9449/brief-c-solution-using-only-strings-and-without-reversal
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m+n, '0');  // the largest length of res  -------------------------------------
        for (int i = m-1; i >= 0; i--) {
            int carry = 0;
            for (int j = n-1; j >= 0; j--) {
                int tmp = res[i+j+1]-'0'+(num1[i]-'0')*(num2[j]-'0')+carry;  // compute from end ----------------------------
                res[i+j+1] = tmp%10 +'0';
                carry = tmp/10;
            }
            res[i] += carry; // res[i] is '0' at first -----------------------------------------
        }
        size_t pos= res.find_first_not_of('0');
        if (pos != string::npos) return res.substr(pos);
        else return "0";
    }
};