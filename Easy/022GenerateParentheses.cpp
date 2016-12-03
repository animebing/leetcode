// lc, rc are the left and right parenthesis you have used, when lc+rc == 2*n, one solution vector is here
// from '(', you can choose left or right parenthesis next, but only when lc is less than rc, you can add ')'

void binaryTree(vector<string> &result, string s, int lc, int rc, int n){
    if (lc+rc == 2*n) {
        result.push_back(s);
        return;
    }
    if (lc < n) binaryTree(result, s+'(', lc+1, rc, n);
    if (rc < lc) binaryTree(result, s+')', lc, rc+1, n);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        string s;
        binaryTree(result, s, 0, 0, n);
        return result;
    }
};
