// based on the solution of shell32 and StefanPochmann, https://discuss.leetcode.com/topic/68174/29-ms-cpp-simple-solution-no-kmp/2
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.size();
        for (int i = 1; i <= len/2; i++)
            if (len%i==0 && (str.substr(i)==str.substr(0, len-i))) // the point is str.substr(i) == str.substr(0, len-i)
                return true;
        
        return false;
    }
};

// some other method based KMP algorithm, which i don't understand yet, so here just post other's solution
// https://discuss.leetcode.com/topic/67652/c-o-n-using-kmp-32ms-8-lines-of-code-with-brief-explanation
// and what is KMP, http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html