// based on the solution of StefanPochmann, use NEWTON METHOD to compute the integer root
// a square number or perfect square is an integer that is the square of an integer
// compute integer square root first,then compare it with square root
// https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        long r = num;
        while (r*r > num)
            r = (r+num/r)/2;
        return r*r == num;
    }
};

// based on the solution of StefanPochmann and https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
// slower than above
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        long r_prev = num, r_cur;
        while (1) {
            r_cur = (r_prev+num/r_prev)/2;
            if (r_prev-r_cur < 1) break; // r_cur is smaller than r_prev, so |r_cur-r_prev| < 1 is same as r_prev-r_cur < 1
            r_prev = r_cur;
        }
        return r_cur*r_cur == num;
    }
};

// based on the solution of xiaohui5319 and jaewoo 
// use binary search, almost the same time as the 1st solution
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        long low = 1, high = num;
        while (low <= high) {
            long middle = (low+high)/2;
            if (middle*middle == num) return true;
            else if (middle*middle < num) low = middle+1;
            else high = middle-1;
        }
        return false;
    }
};