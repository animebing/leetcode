// based on the solution of StefanPochmann
// when i look at the problem, i have no idea how to make connection between character and word
// here use index to implement this
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream in(str);  // clever here to take use of the space in str
        int i = 0, n = pattern.size();
        for (string word; in>>word; i++){
            if (i==n || p2i[pattern[i]]!=w2i[word]) return false;    // i == n means the number of words is larger than that of pattern
            p2i[pattern[i]] = w2i[word] = i+1;                       // p2i[pattern[i]]!=w2i[word] is used check whether the patter is met
        }
        return i == n;                                               // if i != n, here i < n, the number of words is shorter than that of pattern 
    }
};


// based on the solution of ShuangquanLi
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream in(str);
        vector<string> words;
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        string tmp;
        while (in >> tmp) words.push_back(tmp);   // check the number of words and that of characters first
        if (words.size() != pattern.size()) return false;
        
        for (int i = 0; i < pattern.size(); i++){
            if (c2s[pattern[i]]=="" && s2c[words[i]]==0){
                c2s[pattern[i]] = words[i];
                s2c[words[i]] = pattern[i];
                continue;
            }
            if (c2s[pattern[i]] != words[i]) return false;         // here, i always think the usage of s2c is redundant
        }
        return true;
    }
};