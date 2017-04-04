// what i forget: sign, numerator and denominator may be INT_MIN
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if ((numerator>0 && denominator<0) || (numerator<0 && denominator>0)) res.push_back('-');
        long op_1 = abs(long(numerator)), op_2 = abs(long(denominator));    // first type transform, then abs
        
        long q = op_1/op_2;
        long rem = op_1%op_2;
        res += to_string(q);
        if (rem == 0) return res;
        res += '.';
        int i = res.size();
        unordered_map<long, int> rem2idx;  // map between rem and idx in res
        rem2idx[rem] = i;
        
        while (1) {
            op_1 = rem*10;
            q = op_1/op_2;
            rem = op_1%op_2;
            res += q+'0'; // -----------------
            i++;  // -------------------
            if (rem == 0) return res;
            else if (rem2idx.count(rem)) {
                res = res.substr(0, rem2idx[rem]) + "(" + res.substr(rem2idx[rem], i-rem2idx[rem]) + ")";
                return res;
            } else rem2idx[rem] = i; // -----------------------
        }
    }
};

// modification to above code based on solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17071/0ms-c-solution-with-detailed-explanations
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res = "";
        if (numerator<0 ^ denominator<0) res.push_back('-');
        long op_1 = numerator<0 ? (long)numerator * (-1) : (long)numerator;
        long op_2 = denominator<0 ? (long)denominator * (-1) : (long) denominator;
        
        long q = op_1/op_2;
        long rem = op_1%op_2;
        res += to_string(q);
        if (rem == 0) return res;
        res += '.';
        unordered_map<long, int> rem2idx;
        rem2idx[rem] = res.size();
        
        while (1) {
            op_1 = rem*10;
            q = op_1/op_2;
            rem = op_1%op_2;
            res += q+'0';
            if (rem == 0) return res;
            else if (rem2idx.count(rem)) {
                res = res.substr(0, rem2idx[rem]) + "(" + res.substr(rem2idx[rem], res.size()-rem2idx[rem]) + ")";
                return res;
            } else rem2idx[rem] = res.size();
        }
    }
};