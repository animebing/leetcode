// naive solution, build a map from anagram to all words, then assign these words to res
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> anagram;
        for (string str:strs) {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            anagram[tmp].push_back(str);
        }
        for (auto p:anagram) res.push_back(p.second);
        return res;
    }
};

// the solution of jianchao.li.fighter is same as mine and he also use another sort function to sort lowercase string, 
// which is really clever;

string sortStr(string str) {
    int vec[26] = {0};
    for (char c:str) vec[c-'a']++;
    string res(str.size(), 'a');
    int p = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < vec[i]; j++) res[p++] += i;
    }
    return str;
}