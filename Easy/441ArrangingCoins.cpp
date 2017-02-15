// naive solution, try from 1 until the k th staircase can't be formed
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) return 0;
        int res = 1;
        while (n-res >= 0) {
            n -= res;
            res++;
        }
        return res-1;
    }
};

// based on the solution of zmcx16, https://discuss.leetcode.com/topic/65655/c-1-line-code
// 1+2+3+...+x = n, then compute x
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) return 0;
        return floor((sqrt((double)n*8+1)-1)/2);
    }
};



// i can't figure it out completely
// based on the solution of https://discuss.leetcode.com/topic/65690/c-_9ms_accepted
class Solution {
public:
int arrangeCoins(int n) {
    if(n <= 0) return 0;
    long left = 0, right = n;
    while(left <= right){
        long mid = left + (right - left)/2;
        long sum = ((1 + mid) * mid)/2;
        if(sum <= n){left = mid + 1;}
        else {right = mid - 1;}
    }
    return left - 1; // i can't figure out why return left-1
}
};
