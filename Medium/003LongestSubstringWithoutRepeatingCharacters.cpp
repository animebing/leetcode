// find the longest substring without repeated letters from each letter, then compare two find the maximum
// use cnt to record whether a letter occurs or has occurred before, maybe redundant here 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, tmp = 0;
        int cnt[128] = {0};
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            for (; j < s.size(); j++) {
                if (cnt[s[j]] == 0) {
                    tmp++;
                    cnt[s[j]]++;
                }else break;
            }
            if (tmp > max) max = tmp;
            if (j==s.size()-1 || j==s.size()) break;  // check j to reduce iteration times
            tmp = 0;
            for (j = 0; j < 128; j++) cnt[j] = 0;  
        }
        return max;
    }
};

// i use map<char> instead of array, the time is much more than above solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        map<char, int> cnt;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            for (; j < s.size(); j++) {
                if (cnt[s[j]] == 0) {
                    cnt[s[j]]++;
                }else break;
            }
            if (cnt.size() > max) max = cnt.size();
            if (j==s.size()-1 || j==s.size()) break;
            cnt.clear();
        }
        return max;
    }
};


// // based on the solution of lightmark, https://discuss.leetcode.com/category/11/longest-substring-without-repeating-characters
// just one pass to access string s
// i can't understand the solution totally, in my opinion, start means the newest point
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, -1);
        int res = 0, start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] > start) start = dict[s[i]];
            dict[s[i]] = i;
            res = max(res, i-start);
        }
        return res;
    }
};

// based on the solution of dragonmigo, https://discuss.leetcode.com/topic/4083/shortest-o-n-dp-solution-with-explanations
// same as above, dict record the index of each letter appeared last time
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(128, -1);
        int res = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            start = max(dict[s[i]]+1, start);  // from start to current, there is no duplicates
            dict[s[i]] = i;
            res = max(res, i-start+1);
        }
        return res;
    }
};