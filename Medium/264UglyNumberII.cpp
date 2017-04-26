// based on the solution of jmty0083 and explanation of syftalent, https://discuss.leetcode.com/topic/21882/my-16ms-c-dp-solution-with-short-explanation
// https://discuss.leetcode.com/topic/21791/o-n-java-solution
// assuming ugly set S, then we can divide all ugly numbers into 3 groups, each one is S*2, S*3, S*5, and there will be same elements
// in these 3 groups, then we can compare the latest three element in these 3 groups to get the next ugly number
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 1);
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < n; i++) {
            res[i] = min(res[t2]*2, min(res[t3]*3, res[t5]*5));   // minimum of latest elements in these 3 groups
            if (res[i] == res[t2]*2) t2++; // move to next one
            if (res[i] == res[t3]*3) t3++; // move to next one
            if (res[i] == res[t5]*5) t5++; // move to next one
        }
        return res[n-1];
    }
};