// with two preif and compare to decide whether needle is part of haystack
// if haystack.length()=1, needle.length()=0, then
// int a = haystack.length() - needle.length() will not -1, because haystack.length() is 8-byte unsigned integer(size_t), but i can't explain the resulting number
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;
        if (needle.empty()) return 0;
        for (int i = 0; i <= haystack.length() - needle.length(); i++)
            if (haystack.compare(i, needle.length(), needle) == 0) return i;     // haystack.substr(i, needle.length()) == needle
        return -1;
    }
};

// without preif and convert size_t to int
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        for (int i = 0; i <= len1 - len2; i++)
            if (haystack.substr(i, len2, needle) == 0) return i;
        return -1;
    }
};

// without the string method
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        if (len1 < len2) return -1;
        if (len2 == 0) return 0;
        for (int i = 0; i <= len1 - len2; i++){
            int k = i;
            int j;
            for (j = 0; j < len2; j++, k++){
                if (needle[j] != haystack[k]) break;
            }
            if (j == len2) return i;
        }
        return -1;
    }
};
