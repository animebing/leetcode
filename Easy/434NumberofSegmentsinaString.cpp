// initialize a istringtream using a string, then the string will separated by space
class Solution {
public:
    int countSegments(string s) {
        istringstream str(s);
        string tmp;
        int cnt=0;
        while (str>>tmp) cnt++;
        return cnt;
    }
};

// append a space at the end of s, then the combination of a non-space and a following space indicates a segment
class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        s.push_back(' ');
        int cnt = 0;
        for (int i = 0; i < s.size()-1; i++)
            if (s[i]!=' ' && s[i+1]==' ') cnt++;
        
        return cnt;
    }
};

// based on the solution of zyoppy008 
// without appending a space at the end of s, 
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]!=' ' && (s[i+1]==' ' || i+1==s.size())) cnt++; // i+1==s.size() indicates string is over.
        }
        return cnt;
    }
};