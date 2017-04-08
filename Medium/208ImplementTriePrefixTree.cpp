// for Trie, or prefix tree, each node is letter except the root node, a path from root to leaf node is a key
// for each node, it has 26 children, and for each node, there is flag to indicate whether the path from root to current can form a word

struct Node {
    vector<Node *> next;
    bool flag;
    Node (){
        next = vector<Node *>(26, NULL);
        flag = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root(NULL) {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!root) root = new Node;
        if (word.size() == 0) return;
        helper_1(root, word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (!root) return false;
        if (word.size() == 0) return false;
        return helper_2(root, word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (!root) return false;
        if (prefix.size() == 0) return false;
        return helper_3(root, prefix);
    }
private:
    Node* root;
    void helper_1(Node *node, string word) {
        if (word.size() == 0) {
            node->flag = true;
            return;
        }
        if (!node->next[word[0]-'a']) node->next[word[0]-'a'] = new Node;
        helper_1(node->next[word[0]-'a'], word.substr(1));
    }
    bool helper_2(Node *node, string word) {
        if (word.size() == 0) {
            if (node->flag) return true;
            else return false;
        }
        if (!node->next[word[0]-'a']) return false;
        else return helper_2(node->next[word[0]-'a'], word.substr(1));
    }
    bool helper_3(Node *node, string word) {
        if (word.size() == 0) return true;
        if (!node->next[word[0]-'a']) return false;
        else return helper_3(node->next[word[0]-'a'], word.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

// same as above, but use iteration to implement it
class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root(NULL) {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0) return;
        if (!root) root = new Node;
        Node *tmp = root;
        while (word.size()) {
            if (!tmp->next[word[0]-'a']) tmp->next[word[0]-'a'] = new Node;
            tmp = tmp->next[word[0]-'a'];
            word = word.substr(1);
        }
        tmp->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (!root || !word.size()) return false;
        Node *tmp = root;
        while (word.size()) {
            if (!tmp->next[word[0]-'a']) return false;
            tmp = tmp->next[word[0]-'a'];
            word = word.substr(1);
        }
        if (tmp->flag) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (!root || !prefix.size()) return false;
        Node *tmp = root;
        while (prefix.size()) {
            if (!tmp->next[prefix[0]-'a']) return false;
            tmp = tmp->next[prefix[0]-'a'];
            prefix = prefix.substr(1);
        }
        return true;
    }
private:
    Node *root;
};



// based on the solution of makuiyu, https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c
// much concise to use a find function
struct TrieNode {
    TrieNode *next[26];  // ------------------------------
    bool is_word;
    TrieNode (){
        memset(next, 0, sizeof(next));    // -------------------------------
        is_word = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tmp = root;
        for (int i = 0; i < word.size(); i++) {  // use index to access each letter instead of substr
            if (!tmp->next[word[i]-'a']) tmp->next[word[i]-'a'] = new TrieNode;
            tmp = tmp->next[word[i]-'a'];
        }
        tmp->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tmp = find(word); 
        return tmp && tmp->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix);
    }
private:
    TrieNode *root;
    TrieNode *find(string word) {
        TrieNode *tmp = root;
        for (int i = 0; i<word.size() && tmp; i++) {
            tmp = tmp->next[word[i]-'a'];
        }
        return tmp;
    }
};