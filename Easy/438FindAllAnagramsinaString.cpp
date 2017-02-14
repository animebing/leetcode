// match one by one, naive solution, but time exceeds
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        if (s.empty() || p.empty()) return res;
        
        sort(p.begin(), p.end());
        for (int i = 0; i <= s.size()-p.size(); i++) {
            string tmp(s, i, p.size());
            sort(tmp.begin(), tmp.end());
            if (tmp == p) res.push_back(i);
        }
        return res;
    }
};


// based on the solution of i9r0k, https://discuss.leetcode.com/topic/64390/c-o-n-sliding-window-concise-solution
// same sliding window, but concise method
// use two vectors to record the number of appearance of each letter in the sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        if (s.empty() || p.empty()) return res;
        
        vector<int> sv(26, 0), pv(26, 0);
        for (int i = 0; i < p.size(); i++) {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        if (pv == sv) res.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            sv[s[i]-'a']++;
            sv[s[i-p.size()]-'a']--;
            
            if (sv == pv) res.push_back(i-p.size()+1);
        }
        return res;
    }
};
