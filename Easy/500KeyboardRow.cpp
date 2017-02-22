// i am a little frustrate, the answer i wrote is so complex from my perspective, which makes me anxious
// based on the solution of Hcisly, https://discuss.leetcode.com/topic/77778/c-solution-use-bit-manipulations
// so clever solution
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        int dict[26];
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (char c:rows[i]) dict[c-'A'] = 1 << i;
        }
        for (int i = 0; i < words.size(); i++) {
            int r = 7;
            for (char c:words[i]) {
                r &= dict[toupper(c)-'A'];
                if (r == 0) break;
            }
            if (r) res.push_back(words[i]);
        }
        return res;
    }
};


// based on the solution of kevin36, https://discuss.leetcode.com/topic/77761/c-solution
// find out which row the first letter belongs to, then check whether other letters belong to the same row
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row_1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row_2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row_3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<unordered_set<char>> rows = {row_1, row_2, row_3};
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            int r;
            for (int j = 0; j < rows.size(); j++) {
                if (rows[j].count(tolower(words[i][0])) > 0) {
                    r = j;
                    break;
                }
            }
            bool flag = true;
            for (int j = 1; j < words[i].size(); j++) {
                if (rows[r].count(tolower(words[i][j])) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(words[i]);
        }
        return res;
    }
};

// please face to annoying thing correctly