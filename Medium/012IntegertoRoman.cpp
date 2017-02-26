// enumerate the Roman numeral in one, ten, hundred, thousand, then compute the number in each level, find the corresponding
// Roman representation
class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousand {"M", "MM", "MMM"};
        vector<string> hundred {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> ten {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> one {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string res;
        int cnt = 1;
        while (num) {
            int rem = num % 10;
            if (rem != 0){   // if rem is 0, there is no corresponding Roman representation
                string tmp;
                switch (cnt) {
                    case 1: tmp = one[rem-1]; break;
                    case 2: tmp = ten[rem-1]; break;
                    case 3: tmp = hundred[rem-1]; break;
                    case 4: tmp = thousand[rem-1]; break;
                }
                res = tmp + res;
            } 
            cnt++;
            num /= 10;
        }
        return res;
    }
};


// based on the solution of Yuan Zhou, https://discuss.leetcode.com/topic/32333/share-my-python-solution-96ms
// clever solution using the question itself, and deal with 0 case in each level
class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousand {"", "M", "MM", "MMM"};
        vector<string> hundred {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> ten {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> one {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thousand[num/1000] + hundred[(num%1000)/100] + ten[(num%100)/10] + one[num%10];
    }
};


