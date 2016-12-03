// read a char, based on the char before it
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        bool space = false;
        for (int i = 0; i < s.length(); i++){
            if (i==0 && s[i]!=' '){
                cnt++;
                continue;
            }
            if (s[i] != ' '){
                if (s[i-1] == ' ') cnt = 1;
                else cnt++;
            }
        }
        return cnt;
    }
};


// Based on the solution of DriftlessHenry 
// content of in is sepatated by space
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        string last = "";
        while (in >> last);
        return last.length();
    }
};


// Based on the solution of beckswu, this is really cool
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = s.length()-1; i >= 0; i--){
            if (s[i]==' ' && cnt!=0) break;
            if (s[i] != ' ') cnt++;
        }
        return cnt;
    }
};
