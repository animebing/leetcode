// based on the solution of Mad_air and StefanPochmann
// 1. calculate how many digits the number has
// 2. calculate what the number is
// 3. calculate which digit in the number is what we want
// 1-9: 9*1, 10-99: 90*2, 100-999: 900*3
class Solution {
public:
    int findNthDigit(int n) {
        n--;  // clever here, then access is more easy
        long base = 1;
        int digits = 1;
        while (1) {
            if (n < 9*base*digits) {
                int num = base+n/digits;
                int idx = n%digits;
                return to_string(num)[idx]-'0';
            }
            n -= 9*base*digits;
            base *= 10;
            digits++;
        }
    }
};

// the same idea as above
class Solution {
public:
    int findNthDigit(int n) {
        n--;
        long base = 1;
        int digits = 1;
        // 1
        while (1){
            if (n < 9*base*digits) break;
            n -= 9*base*digits;
            base *= 10;
            digits++;
        }
        
        // 2
        int num = base + n/digits;
        
        // 3
        int idx = n%digits;
        int rem;
        for (int i = 0; i <= digits-1-idx; i++) {
            rem = num % 10;
            num /= 10;
        }
        
        return rem; 
        
    }
};


