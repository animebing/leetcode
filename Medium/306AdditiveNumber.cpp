// based on the solution of zjh08177, https://discuss.leetcode.com/topic/29872/0ms-concise-c-solution-perfectly-handles-the-follow-up-and-leading-0s
// try all possible first two numbers, use check function to do recursively
// enumerate the length of first and second number, and the length should be less than or equal to the length of half, use it to do pruning 
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size()/2; i++) {
            for (int j = 1; j <= (num.size()-i)/2; j++) {
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
private:
    bool check(string num1, string num2, string num) {
        if ((num1.size()>1 && num1[0]=='0') || (num2.size()>1 && num2[0]=='0')) return false;
        string sum = add(num1, num2);
        if (sum == num) return true;
        if (num.size()<=sum.size() || sum.compare(num.substr(0, sum.size()))!=0) return false;
        else return check(num2, sum, num.substr(sum.size()));
    }
    
    string add(string num1, string num2) {
        string res;
        int carry = 0, i = num1.size()-1, j = num2.size()-1;
        while (i>=0 || j>=0 || carry!=0) {
            int tmp = 0;
            if (i >= 0) tmp += num1[i--]-'0';
            if (j >= 0) tmp += num2[j--]-'0';
            tmp += carry;
            carry = tmp/10;
            res.push_back(tmp%10+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
};
