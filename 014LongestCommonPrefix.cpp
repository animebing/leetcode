// 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.empty()) return result;
        string base = strs[0];
        bool flag = false;
        for (int i = 0; i < base.length(); i++){
            vector<string>::iterator iter = strs.begin()+1;
            for (; iter < strs.end(); iter++){
                if (i == (*iter).length() || base[i] != (*iter)[i]){
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            result.push_back(base[i]);
        }
        return result;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return string("");
        if (strs.size() == 1) return strs[0];
        string base = strs[0];
        for (int i = 0; i < base.length(); i++)
            for (int j = 1; j < strs.size(); j++)
                if (i == strs[j].length() || strs[j][i] != base[i])
                    return string(base, 0, i);
        return base;
    }
};