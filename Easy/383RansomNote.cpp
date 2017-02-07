// based on the idea of intersection set of two vectors
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> c2n;
        for (auto c:ransomNote) c2n[c]++;  // record the number of occurrence of each letter
        for (auto c:magazine)
            if (c2n[c] > 0) c2n[c]--;  // decrease c2n[c] by one only when c is in ransomNote
        
        for (auto c:ransomNote)  
            if (c2n[c] != 0) return false;  
        
        return true;
        
        
    }
};

// sort two strings first, then get the intersection letter of two sorted string and stored in the ransomNote string
// if the return iterator is equals to ransomNote.end(), then the intersection is ransomNote itself, so return true;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        string::iterator res = set_intersection(ransomNote.begin(), ransomNote.end(), magazine.begin(), magazine.end(), ransomNote.begin());
        return res == ransomNote.end();
        
    }
};
// same as 2nd solution, but not use set_intersetion, just compare by hand
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;  // important, i forget this in above solution
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int i = 0, j = 0;
        while (i<ransomNote.size() && j<magazine.size()) {
            if (magazine[j] == ransomNote[i]) i++;
            j++;
        }
        return i==ransomNote.size();
        
    }
};

// based on the solution of haruhiku 
// same idea as my 1st solution, but a bit different. because i want to know whether letters of ransomNote are in magazine
// it is more reasonable to compute c2n in magazine, then check every letter in ransomNote
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        unordered_map<char, int> c2n;
        for (auto c:magazine) c2n[c]++;
        for (auto c:ransomNote) if (--c2n[c] < 0) return false;
        return true;
    }
};