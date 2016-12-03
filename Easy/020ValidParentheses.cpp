// use stack to store unmatched parenthesis
// but it is not considered well, because just left parenthesis should be pushed into the stack
class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2) return false;
        stack<char> match;
        for (int i = 0; i <s.length(); i++){
            if (match.empty()) match.push(s[i]);
            else{
                char top_ele = match.top();
                if ((top_ele=='(' && s[i]==')') || (top_ele=='[' && s[i]==']') || (top_ele=='{' && s[i]=='}'))
                    match.pop();
                else match.push(s[i]);
            }
        }
        if (match.empty()) return true;
        else return false;
    }
};


// better solution by others
class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2) return false;
        stack<char> left;
        map<char, char > match = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (int i = 0; i < s.length(); i++){
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') left.push(s[i]);
            else if (!left.empty() && match[left.top()] == s[i]) left.pop();
            else return false;
        }
        return left.empty();
    }
};

// at first, i think just return true after for loop, but when i submit, the wrong case indicates that maybe there is just left parenthesis in string s.
