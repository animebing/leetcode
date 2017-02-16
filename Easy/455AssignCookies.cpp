// sort g and s first, try to satisfy the child with smallest greed factor using the smallest cookie
// then another child
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j= 0;
        int res = 0;
        while (i<g.size() && j<s.size()) {
            for (int t = j; t < s.size(); t++) {
                if (g[i] <= s[t]) {
                    res++;
                    j = t+1;   // important here to make the next search follow previous one
                    break;
                }
            }
            i++;
        }
        return res;
    }
};


// based on the solution of amanchik, https://discuss.leetcode.com/topic/68455/array-sort-two-pointer-greedy-solution-o-nlogn
// the same idea as mine, but more concise
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j= 0;
        while (i<g.size() && j<s.size()) {
            if (g[i] <= s[j]) {   // more concise here
                i++;
                j++;
            }else j++;
        }
        return i;
    }
};