// stay here, i can't understand the solution totally
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int residual;
        while (n){
            n--;
            residual = n % 26;
            res.push_back(residual+'A');
            n /= 26;
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};