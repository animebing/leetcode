// sort citations decreasingly , then from the first one, if the citation of this paper is bigger than current h plus 1, then 
// I can increase h by 1, do until the condition can't be met
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        sort(citations.begin(), citations.end(), [](int a, int b){return a>b;});
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h+1) h++;
            else break;
        }
        return h;
    }
};


// maintain a vector to record the number of papers for citation number, then from the one with largest citation
// until we find the accumulated number of papers is larger than or equal to citation
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        vector<int> c2num(n+1, 0);
        for (int c : citations) {
            if (c >= n) c2num[n]++;   // --------------------------
            else c2num[c]++;
        }
        int t = 0;
        for (int i = n; i >= 1; i--) {
            t += c2num[i];
            if (t >= i) return i;
        }
        return 0;
    }
};