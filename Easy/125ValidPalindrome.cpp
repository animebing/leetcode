// alphanumerical  alpha and number, english.....
bool isAlpha(char c){
    if ((c>= 'a'&&c<='z') || (c>='A'&&c<='Z')) return true;
    else return false;
}
bool isNumber(char c){
    if (c>='0' && c<='9') return true;
    else return false;
}
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = (int)s.size() -1;
        while (i <= j){
            if (!isAlpha(s[i]) && !isNumber(s[i])){
                i++;
                continue;
            }
            if (!isAlpha(s[j]) && !isNumber(s[j])){
                j--;
                continue;
            }
            if (isNumber(s[i]) && isNumber(s[j])){
                if (s[i] == s[j]){
                    i++;
                    j--;
                }else return false;
            }else if (isAlpha(s[i]) && isAlpha(s[j])){
                if (s[i]==s[j] || abs(s[i]-s[j])=='a'-'A'){
                    i++;
                    j--;
                }else return false;
            }else return false;
        }
        return true;
    }
};

// based on the solution of satyakam and lester_zhang 
// isalnum and tolower in cctype header file
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = (int)s.size()-1;
        while(i < j){
            if (isalnum(s[i]) == 0) i++;
            else if (isalnum(s[j]) == 0) j--;
            else if (tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};