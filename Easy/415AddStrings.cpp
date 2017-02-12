// reverse two string first in order to compute from least important digit
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty()) return num1+num2;
        string res;
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            int digit_1 = i<num1.size() ? num1[i]-'0' : 0;
            int digit_2 = i<num2.size() ? num2[i]-'0' : 0;
            res.push_back((digit_1+digit_2+carry)%10+'0');
            carry = (digit_1+digit_2+carry)/10;
        }
        if (carry != 0) res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
};

// based on the solution of jasonshieh, https://discuss.leetcode.com/topic/62305/c-_accepted_13ms
// without reversing string
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty()) return num1+num2;
        string res;
        int carry = 0, idx_1 = num1.size()-1, idx_2 = num2.size()-1;
        while (idx_1>=0 || idx_2>=0 || carry) {
            int sum = 0;
            if (idx_1 >= 0) sum += num1[idx_1--]-'0';
            if (idx_2 >= 0) sum += num2[idx_2--]-'0';
            sum += carry;
            res = to_string(sum%10)+res;
            carry = sum/10;
        }
        return res;
    }
};