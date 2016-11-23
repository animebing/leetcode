// string method
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        int len = str.length();
        for (int i = 0; i < len/2; i++){
            if (str[i] != str[len-1-i]) return false;
        }
        return true;
    }
};
// compare the first and the last num, attention to the base /= 100
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int base = 1;
        int tmp = x;
        while (tmp /10){
            tmp /= 10;
            base *= 10;
        }
        tmp = x;
        int a, b;
        while (tmp != 0){
            a = tmp/base;
            b = tmp%10;
            if (a != b) return false;
            tmp = (tmp%base)/10;
            base /= 100;
        }
        return true;
    }
};