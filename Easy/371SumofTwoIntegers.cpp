// based on the solution of vdvvdd and LHearen
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while (b) {
            a = sum^b; // calculate sum without thinking of carry
            b = (sum&b)<<1; // calculate carry
            // bitset<32> bit_cnt(b);   // use this to demonstrate the carry will be zero at last
            // cout << bit_cnt.count() << endl;
            sum = a;
        }
        return sum;
    }
};