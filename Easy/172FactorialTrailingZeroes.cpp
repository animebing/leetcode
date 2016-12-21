// compute n! first, then divided by 10 until the remainder is not 0
class Solution {
public:
    int trailingZeroes(int n) {
        int f = 1, res = 0;
        for (int i = n; i >1; i--) f *= i;
        cout << INT_MAX << endl;
        cout << f << endl;
        while (1){
            int residual = f % 10;
            if (residual != 0) break;
            res++;
            f /= 10;
        }
        return res;
    }
};


// wikipedia and De Polignac's formula
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long base = 5;   // when base is overflow, then tmp may be not zeor while it should be, then res will be larger than expected
        while (1){
            int tmp = n / base;
            if (tmp == 0) break;
            res += tmp;
            base *= 5;
        }
        return res;
    }
};

// just divided by 5 every time, maybe there are some property about floor function
class Solution {
public:
    int trailingZeroes(int n) {   // return n ? 0 : n/5 + trailingZeros(n/5), based on the solution of xcv58 
        int res = 0;
        while (n){
            n /= 5;
            res += n;
        }
        return res;
    }
};
