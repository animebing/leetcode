// from tail to head, choose a substr post from the tail, if post is a palindrome, then we can get the partitions
// of the left substring, then combine each partition with post, we can get new partition of longer string
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return {};
        vector<vector<string>> res;
        for (int i = s.size()-1; i >= 0; i--) {
            string post = s.substr(i);
            if (isPalindrome(post)) {
                vector<string> tmp{post};
                vector<vector<string>> pre_par = partition(s.substr(0, i));
                if (pre_par.empty()) res.push_back(tmp);
                else {
                    for (int j = 0; j < pre_par.size(); j++) {
                        pre_par[j].push_back(post);
                        res.push_back(pre_par[j]);
                    }
                }
            }
        }
        return res;
    }
private:
    bool isPalindrome(string str) {
        if (str.size() == 0) return false;
        int low = 0, high = str.size()-1;
        while (low < high) {
            if (str[low] != str[high]) return false;
            low++;
            high--;
        }
        return true;
    }
};



// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15432/12ms-14-lines-c
// backtraking method, i am messed with backtracking
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return {};
        vector<vector<string>> res;
        vector<string> com;
        helper(res, com, 0, s);
        return res;
    }
private:
    void helper(vector<vector<string>> &res, vector<string> &com, int start, string s) {
        if (start == s.size()) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string tmp = s.substr(start, i-start+1);
            int low = start, high = i;
            while (low<high && s[low]==s[high]) {
                low++;
                high--;
            }
            if (low >= high) {
                com.push_back(tmp);
                helper(res, com, i+1, s);
                com.pop_back();
            }
        }
    } 
};