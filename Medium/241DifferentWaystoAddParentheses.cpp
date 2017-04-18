// based on the solution of Gcdofree, https://discuss.leetcode.com/category/302/different-ways-to-add-parentheses
// divide and conquer, for each operator, find result_1 of previous string, and result_2 of later string, then combine them
// with operator to get overall results 
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.size() == 0) return {};
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c=='+' || c=='-' || c=='*') {
                vector<int> tmp_1 = diffWaysToCompute(input.substr(0, i));
                vector<int> tmp_2 = diffWaysToCompute(input.substr(i+1));
                for (int v_1 : tmp_1) {
                    for (int v_2 : tmp_2) {
                        if (c == '+') res.push_back(v_1+v_2);
                        else if (c == '-') res.push_back(v_1-v_2);
                        else res.push_back(v_1*v_2);
                    }
                }
            }
        }
        if (res.size() == 0) res.push_back(stoi(input)); // recursion stop condition
        return res;
    }
};




// based on the solution of Gcdofree, https://discuss.leetcode.com/category/302/different-ways-to-add-parentheses
// there may be many repeated string, so here use a map to store them, if a string is in map, we can get the result directly, 
// or we need to compute them, then insert them into the map for potential use
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.size() == 0) return {};
        unordered_map<string, vector<int>> dp;
        return computeWithMap(input, dp);
    }
private: 
    vector<int> computeWithMap(string input, unordered_map<string, vector<int>> &dp) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c=='+' || c=='-' || c=='*') {
                vector<int> tmp_1;
                if (dp[input.substr(0, i)].size() != 0) tmp_1 = dp[input.substr(0, i)];
                else tmp_1 = computeWithMap(input.substr(0, i), dp);
                vector<int> tmp_2;
                if (dp[input.substr(i+1)].size() != 0) tmp_2 = dp[input.substr(i+1)];
                else tmp_2 = computeWithMap(input.substr(i+1), dp);
                for (int v_1 : tmp_1) {
                    for (int v_2 : tmp_2) {
                        if (c == '+') res.push_back(v_1+v_2);
                        else if (c == '-') res.push_back(v_1-v_2);
                        else res.push_back(v_1*v_2);
                    }
                }
            }
        }
        if (res.size() == 0) res.push_back(stoi(input));
        dp[input] = res;
        return res;
    }
};