// record the number of occurrence of each letter in s, then check whether there is a letter just appear once   
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> c2n;
        for (auto c:s) c2n[c]++;
        int idx = 0;
        for (auto c:s) {
            if (c2n[c] == 1) return idx;
            idx++;
        }
        return -1;
            
    }
};

// based on the solution of dr.pro
// use two map to record number and index
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> c2n, c_idx;
        for (int i = 0; i < s.size(); i++) {
            c2n[s[i]]++;
            c_idx[s[i]] = i;
        }
        int idx = s.size();
        for (auto p:c2n) {
            if (p.second == 1) idx = min(idx, c_idx[p.first]);  // use this to get smaller idx
        }
        return idx==s.size() ? -1 : idx;
            
    }
};