// Trie(prefix tree) structure, i am tring to implement it using a simple way like Implement Trie (Prefix Tree), but i don't find the way
struct TrieNode {
    bool is_word;
    TrieNode *next[26];  // -----------------
    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; i++) next[i] = NULL; // ---------------------  memset(next, 0, sizeof(next));
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size(); i++) {
            if (!tmp->next[word[i]-'a']) tmp->next[word[i]-'a'] = new TrieNode;
            tmp = tmp->next[word[i]-'a'];
        }
        tmp->is_word = true; // -------------------------
    } 
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (helper(root, word)) return true;
        else return false;
    }
private:
    TrieNode *root;
    bool helper(TrieNode *node, string word) {
        if (word.size() == 0) {
            if (node->is_word) return true;
            else return false;
        }
        if (word[0] == '.') { // --------------------
            for (int i = 0; i < 26; i++) {
                if (node->next[i]) {
                    if (helper(node->next[i], word.substr(1))) return true;
                }
            }
            return false;
        } else {
            if (!node->next[word[0]-'a']) return false;
            else return helper(node->next[word[0]-'a'], word.substr(1));
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15581/80ms-clear-c-code-with-detailed-explanations
// but i prefer to my solution 
    bool helper(TrieNode *node, string word) {
        TrieNode *run = node;
        for (int i = 0; i<word.size() && run; i++) {
            if (word[i] != '.') run = run->next[word[i]-'a'];
            else {
                for (int j = 0; j < 26; j++) 
                    if (helper(run->next[j], word.substr(i+1))) return true;
                return false;
            }
        }
        return run && run->is_word;
    }
