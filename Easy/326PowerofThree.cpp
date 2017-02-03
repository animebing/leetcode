// naive solution, maybe wrong
/*
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (1) {
            int rem = n % 3;
            n /= 3;
            if (n && rem) return false;
            if (n==0 && rem==1) return true;
        }
    }
};
*/

// based on the solution of ElementNotFoundException 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 1)
            while (n%3 == 0) n /= 3;
        
        return n == 1;
    }
};

// based on the solution of StefanPochmann   
// for signed 32int, the biggest power of 3 is 3^19, we also can enumerate all possible values here
// refered to http://stackoverflow.com/questions/1804311/how-to-check-if-an-integer-is-a-power-of-3/24274850#24274850
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && (int)pow(3, 19)%n==0;
    }
};