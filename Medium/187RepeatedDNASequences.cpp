// for each 10-letter substring, count the number of occurrence, when the number is 1, push the substring into res
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<string, int> str2num;
        vector<string> res;
        for (int i = 0; i <= s.size()-10; i++) {
            string tmp = s.substr(i, 10);
            if (str2num[tmp] == 1) res.push_back(tmp);
            str2num[tmp]++;
        }
        return res;
    }
};


// based on the solution of crazyirontoiletpaper, https://discuss.leetcode.com/topic/8894/clean-java-solution-hashmap-bits-manipulation
// same idea as before, but use a 2 bits to encode a letter, use the encoded int as key in map, a little faster that above solution 
// how to encode string? bit?
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<int, int> str2num;
        vector<string> res;
        int letter2int[26] = {0}; // -------------
        letter2int['C'-'A'] = 1;
        letter2int['G'-'A'] = 2;
        letter2int['T'-'A'] = 3;
        for (int i = 0; i <= s.size()-10; i++) {
            int v = 0;
            for (int j = i; j < i+10; j++) {
                v |= letter2int[s[j]-'A'];
                v <<= 2;
            }
            if (str2num[v] == 1) res.push_back(s.substr(i, 10));
            str2num[v]++;
        }
        return res;
    }
};