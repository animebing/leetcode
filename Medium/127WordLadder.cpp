// try to use graph BFS to solve the problem, but here 29 cases passed, then time limit exceeded
// here BFS, in order to record the len, I traverse level by level, for each word in the queue, I will try to change each letter
// once, if the changed word is in word list, then push into queue, for graph, I maintain a visited set to avoid forming a cycle

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) return 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        while (!q.empty()) {
            len++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string tmp_1 = q.front();
                q.pop();
                if (tmp_1 == endWord) return len;
                if (visited.count(tmp_1) == 0) {
                    visited.insert(tmp_1);
                    for (int j = 0; j < tmp_1.size(); j++) {
                        for (int t = 0; t < 26; t++) {
                            string tmp_2 = tmp_1;
                            if (tmp_2[j]-'a' != t) {
                                tmp_2[j] = 'a'+t;
                                if (find(wordList.begin(), wordList.end(), tmp_2) != wordList.end()) {
                                    q.push(tmp_2);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};


// I sort the wordList first, then use my own binary search function to replace the find function, then it is accepted
// i am happy, 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) return 0;
        if (wordList.size() == 0) return 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        sort(wordList.begin(), wordList.end());
        while (!q.empty()) {
            len++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string tmp_1 = q.front();
                q.pop();
                if (tmp_1 == endWord) return len;
                if (visited.count(tmp_1) == 0) {
                    visited.insert(tmp_1);
                    for (int j = 0; j < tmp_1.size(); j++) {
                        for (int t = 0; t < 26; t++) {
                            string tmp_2 = tmp_1;
                            if (tmp_2[j]-'a' != t) {
                                tmp_2[j] = 'a'+t;
                                if (biSearch(wordList, tmp_2)) {
                                    q.push(tmp_2);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
private:
    bool biSearch(vector<string> &wordList, string target) {
        int low = 0, high = wordList.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (wordList[mid] == target) return true;
            if (wordList[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};


// modification of my previous solution based on jianchao.li.fighter, https://discuss.leetcode.com/topic/16983/easy-76ms-c-solution-using-bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) return 0;
        if (wordList.size() == 0) return 0;
        unordered_set<string> visited;
        visited.insert(beginWord); 
        queue<string> q;
        q.push(beginWord);
        int len = 0;
        sort(wordList.begin(), wordList.end());
        while (!q.empty()) {
            len++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) return len;
                for (int j = 0; j < word.size(); j++) {
                    char letter = word[j];   // --------------------------- clever 
                    for (int t = 0; t < 26; t++) {
                        word[j] = 'a'+t;
                        if (biSearch(wordList, word) && visited.count(word)==0) { // check visited here, then insert,
                            q.push(word);                                         // so I need to insert beginWord at first
                            visited.insert(word);
                        }
                    }
                    word[j] = letter;  // ------------------------------ clever
                }
            }
        }
        return 0;
    }
private:
    bool biSearch(vector<string> &wordList, string target) {
        int low = 0, high = wordList.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (wordList[mid] == target) return true;
            if (wordList[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};