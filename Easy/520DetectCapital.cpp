// compute how many uppercase letters and lowercase letters are in the word
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 0) return false;
        int up = 0, low = 0;
        for (char l:word) {
            if (l>='A' && l<='Z') up++;
            else low++;
        }
        if (up==word.size() || low==word.size()) return true;
        else if (up==1 && (word[0]>='A' && word[0]<='Z')) return true;
        else return false;
    }
};

// python solution https://discuss.leetcode.com/topic/79951/in-python-these-are-called/2
// count_if solution https://discuss.leetcode.com/topic/80314/6ms-2-lines-c-solution