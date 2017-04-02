// use istringstream to bind with input s, then get strings separated by spaces from istringstream one by one
// then reverse all words and form new long strings
class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0) return;
        vector<string> words;
        istringstream s_stream(s);
        string tmp;
        while (s_stream >> tmp) words.push_back(tmp);
        if (words.empty()) {   // ATTENTION HERE, I forget to check this 
            s = "";
            return;
        }
        reverse(words.begin(), words.end());
        string res = words[0];
        for (int i = 1; i < words.size(); i++) res += " "+words[i];
        s = res;
    }
};

// based on the solution of JackBauer, https://discuss.leetcode.com/topic/5319/c-solution-in-place-runtime-o-n-memory-o-1
// erase redundant space first, and reverse each word, at last reverse the whole string
// there is a solution, reverse the string first, then reverse each word, almost same as above
// what i have learn: use word_flag to indicate this is the first word
class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0) return;
        int i = 0, j = 0;
        bool word_flag = false;
        while (i < s.size()) {
            while (i<s.size() && s[i]==' ') i++;
            if (i == s.size()) break;
            if (word_flag) s[j++] = ' ';
            int tmp = j;
            while (i<s.size() && s[i]!=' ') s[j++] = s[i++];
            word_flag = true;
            helper(s, tmp, j-1);
        }
        s.resize(j);
        helper(s, 0, j-1);
    }
private:
    void helper(string &s, int left, int right) {
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};