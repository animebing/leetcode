// multiple pass, first for finding all bulls position and flag them, second pass to count the number of occurrence of cows
// for cows number, find the minumum for cnt_1 and cnt_2
// ATTENTION: first i want to use map to do the counting job, but later I find it's better to use vector, because there 
// are only 10 different numbers from 0 to 1
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<bool> flag(n, false);
        vector<int> cnt_1(10, 0), cnt_2(10, 0);
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                flag[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!flag[i]) {
                cnt_1[secret[i]-'0']++;
                cnt_2[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++) cows += min(cnt_1[i], cnt_2[i]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};


// improvement based on the solution of moumoutsay, https://discuss.leetcode.com/topic/28445/c-4ms-straight-forward-solution-two-pass-o-n-time
// more concise solution
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        vector<int> cnt_1(10, 0), cnt_2(10, 0);
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                cnt_1[secret[i]-'0']++;
                cnt_2[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++) cows += min(cnt_1[i], cnt_2[i]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};