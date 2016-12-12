// use the result of last state to update current state, just push_back(1) at the beginning
// caution: from right to left to updata to avoid overriding
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; i++){
            res.push_back(1);
            for (int j = i-1; j > 0; j--)
                res[j] = res[j-1]+res[j];
        }
        return res;
    }
};


// Based on the solution of hanhongsun
// clever finding: each row of Pascal triangle is the combination number of C(n, k), where k = 0,...,n
// and C(n, k) = C(n, k-1)*(n-k+1)/k
// and each row is symmetric, so i just need to compute the left part
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        long comb = 1; // here comb = res[0]
        for (int i=1, j=rowIndex-1; i <= rowIndex/2; i++, j--){
            comb *= (rowIndex+1-i);    // res[i] = res[j] = res[i-1]*(unsigned long)(rowIndex+1-i)/(unsigned long)i
            comb /= i;
            res[i] = comb;
            res[j] = comb;
        }
        return res;
    }
};


