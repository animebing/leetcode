// use backtracking, there are many cases that don't meet the requirement for ip
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size()==0 || s.size()>12) return {};
        vector<string> res;
        string com;
        helper(s, res, com, 0, 4);
        return res;
    }
private:
    void helper(string s, vector<string> &res, string com, int start, int left) {
        // start: start index, left: the number of part we need
        int n = s.size();
        if (left == 0) {
            if (start == n) res.push_back(com);
            return;
        }
        if (left != 4) com.push_back('.');   // -------------------
        for (int i = 1; i <=3 ; i++) {
            if (start+i > n) break;  // --------------------
            int tmp = 0;
            if (i == 2) {  // >= 10
                tmp += (s[start]-'0')*10 + s[start+1]-'0';
                if (tmp < 10) continue;
            }
            if (i == 3) {  // >= 100 and <= 255
                tmp += (s[start]-'0')*100 + (s[start+1]-'0')*10 + s[start+2]-'0';
                if (tmp < 100 || tmp > 255) continue;   
            }
            com += s.substr(start, i);
            helper(s, res, com, start+i, left-1);
            for (int j = 0; j < i; j++) com.pop_back(); // -------------- 
        }
    }
};