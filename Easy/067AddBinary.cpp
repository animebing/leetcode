// let a be the longer string, deal with two conditions

class Solution {
public:
    string addBinary(string a, string b) {
        string tmp;
        if (a.length() < b.length()){
            tmp = a;
            a = b;
            b = tmp;
        }
        int diff = (int)(a.length()-b.length());
        int inc = 0;
        int i;
        for (i = b.length()-1; i >= 0; i--){
            char tmp = (b[i]-'0' + a[i+diff]-'0'+inc)%2 + '0';
            inc = (b[i]-'0' + a[i+diff]-'0'+inc)/2;
            a[i+diff] = tmp;
        }
        if (inc == 0) return a;
        for (i = i+diff; i >=0; i--){
            if (a[i] == '1') a[i] = '0';
            else
            {
                a[i] = '1';
                return a;
            }
        }
        a.insert(a.begin(), '1');
        return a;
    }
};

// within one loop, much conciser, carry == 1 in case there is a carry in the most significant bit.
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0, i = a.length()-1, j = b.length()-1;
        while (i>=0 || j>=0 || carry==1){
            carry += i>=0 ? a[i--]-'0' : 0;
            carry += j>=0 ? b[j--]-'0' : 0;
            result = char(carry%2+'0')+result;
            carry /= 2;
        }
        return result;
    }
};
