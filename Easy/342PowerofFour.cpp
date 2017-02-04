// decide whether num is the power of 2, then get the result of log2, decide whether it can be divided by 2
// if ceil and floor of a number is same, then it is an integer
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        double d_num = log2((double)num);
        if (ceil(d_num) != floor(d_num)) return false;
        int i_num = d_num;
        return i_num%2 == 0;
    }
};

// naive solution, same as the power of 3
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num > 1)
            while (num%4 == 0) num /= 4;
            
        return num == 1;
    }
};

// based on the solution of Beibeibei, discussion of kleklokin, gaojianchao1991 and hua_usa
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && ((num&(num-1))==0) && ((num-1)%3==0);  // caution, the priority of == is higher than &
    }
};

// based on the solution of DaHaSong 
// use num&0x55555555 to check whether it is the power of 5 in the condition that it has been the power of 2
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && ((num&(num-1))==0) && (num&0x55555555);
    }
};


