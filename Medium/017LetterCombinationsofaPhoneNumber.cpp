// start from an empty string, for letters of each number, add the current string, then recursion
unordered_map<char, string> num2letter = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "kjl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void helper(string seq, string digits, int idx, vector<string> &res) {
    if (idx == digits.size()) {
        res.push_back(seq);
        return;
    }
    if (digits[idx]=='0' || digits[idx]=='1') return;  // there is somethins wrong about how to deal with '0' and '0', i have try numbers
    string letter = num2letter[digits[idx]];           // with '0' and '1', the res is []
    for (int i = 0; i < letter.size(); i++) {
        string tmp;
        tmp.push_back(letter[i]);  
        helper(seq+tmp, digits, idx+1, res); // helper(seq+letter[i], digits, idx+1, res) is okay, string + char returns a string
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string b = "bing";
        b = b + 'a';
        cout << b << endl;
        vector<string> res {};
        if (digits.size() == 0) return res;
        string seq = "";
        helper(seq, digits, 0, res);
        return res;
    }
};

// based on the solution of peerlessbloom, https://discuss.leetcode.com/topic/3396/my-iterative-sollution-very-simple-under-15-lines
// iterative solution, find all combination of previous numbers, for each of these combination, add a new letter of new number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        res.push_back("");  // -----------------------------------------
        vector<string> nums = {"", "", "abc", "def", "ghi", "kjl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i]=='0' || digits[i]=='1') {
                res.clear();
                break;
            }
            string letters = nums[digits[i]-'0'];
            vector<string> tmp; // ---------------------------------------
            for (int j = 0; j < letters.size(); j++) {
                for (int t = 0; t < res.size(); t++) {
                    tmp.push_back(res[t]+letters[j]);
                }
            }
            res = tmp; // ------------------------------
        }
        return res;  
    }
};