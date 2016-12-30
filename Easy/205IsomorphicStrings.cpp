// use two maps, one is used to determine whether a pair of <s[i], t[i]> have been appeared, if so, the next t[j] with same s[j] should be same
// another is used to determine whether two different characters map to a same character
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s2t;
        map<char, int> t_num;
        for (int i = 0; i < s.size(); i++){
            if (s2t[s[i]] == 0){
                s2t[s[i]] = t[i];
                if (++t_num[t[i]] == 2) return false;  // haha
            }else {
                if (s2t[s[i]] != t[i]) return false;   // haha
            }
        }
        return true;
    }
};


// based on the solution of xh23123 
// it is very clever that we don't need to compare the value in string
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_num[128]={0}, t_num[128]={0};
        for (int i = 0; i < s.size(); i++){
            if (s_num[s[i]] != t_num[t[i]]) return false;
            s_num[s[i]] = i+1;
            t_num[t[i]] = i+1;
        }
        return true;
    }
};