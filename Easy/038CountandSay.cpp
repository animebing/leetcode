// begin from n = 1, then generate i based on i-1
// use cnt to record how many times a char occurs repeatedly
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return string("1");
        string prev = "1";
        string cur;
        for (int i = 2; i <= n; i++){
            int cnt = 1;
            for (int j = 0; j < prev.length(); j++){
                if (j == prev.length()-1){
                    cur.push_back(cnt+'0');
                    cur.push_back(prev[j]);
                    break;
                }
                if (prev[j+1] == prev[j]) cnt++;
                else{
                    cur.push_back(cnt+'0');
                    cur.push_back(prev[j]);
                    cnt = 1;
                }
            }
            prev = cur;
            cur.clear();
        }
        return prev;
    }
};


// Based on the solution of wayne5 
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        while (--n){
            string tmp = "";
            int idx = 0;
            char c = result[0];
            for (int i = 1; i < result.length(); i++){
                if (result[i] != c){
                    tmp.push_back('0'+i-idx);
                    tmp.push_back(c);
                    c = result[i];
                    idx = i;
                }
            }
            tmp.push_back('0'+result.length()-idx);
            tmp.push_back(c);
            result = tmp;
        }
        return result;
    }
};
