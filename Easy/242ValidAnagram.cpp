// use two maps to record the number of occurence of each letter, 
// then compare these two maps whether they are the same
// 66ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> s_map, t_map;
        for (int i = 0; i < s.size(); i++){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        map<char, int>::iterator iter = s_map.begin();        // for (auto & x : s_map){
        for (; iter!=s_map.end(); iter++){                    //  if (x.second != t_map[x.first]) return false;
            if (iter->second!=t_map[iter->first]) return false;  // }
        }
        return true;
    }
};

// based on the solution of jianchao.li.fighter
// use just one unordered_map(Hash by jianchao.li.fighter) to count the times of appearance
// of each letter in s and t, for each letter in s, it increases the counter by 1 while decrease the
// counter by 1 in t, if t is the anagram of s, then all elements in t should be zero
// 36ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> counts;
        for (int i = 0; i < s.size(); i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto & x:counts){
            if (x.second) return false;
        }
        return true;
    }
};

// based on the solution of jianchao.li.fighter
// the same idea as above, but use array to record the count because all letter is lowercase, but speed up
// 9ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt[26] = {0}; // int cnt[26] = {} // initialize all elements with 0, but cnt[26] = {1} will initialize the first one with 1, others 0.
        for (int i = 0; i < s.size(); i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (cnt[i]) return false;
        
        return true;
    } 
};

// based on the solution of jianchao.li.fighter
// sort two strings first, if t is the anagram of s, then sorted strings should be equal to each other
// 79 ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return false;    // 66ms
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    } 
};