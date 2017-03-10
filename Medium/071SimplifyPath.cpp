// based on the solution of monaziyi, https://discuss.leetcode.com/topic/8678/c-10-lines-solution
// the point here is using getline to do string splitting by '/'
#include <string> // for string and getline
#include <vector> // for vector
#include <sstream> // for stringstream
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> sep_path;
        string tmp;
        stringstream sstr(path);
        while (getline(sstr, tmp, '/')) {
            if (tmp=="" || tmp==".") continue; // ------------------------------
            if (tmp==".." && !sep_path.empty()) sep_path.pop_back();  // ----------------------
            if (tmp != "..") sep_path.push_back(tmp);
        }
        if (sep_path.empty()) return "/";
        string res;
        for (auto str:sep_path) res += "/" + str;
        return res;
    }
};