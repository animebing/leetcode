// use to_string to convert an int to string, then calculate sum of all digits using string
// if num / 10 is 0, then it is over
class Solution {
public:
    int addDigits(int num) {
        while(1){
            if (num/10 == 0) return num;
            string str = to_string(num);
            num = 0;
            for (int i = 0; i < str.size(); i++) num += str[i]-'0';
        }
    }
};

// the problem is digit root
// i get the answer from https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};