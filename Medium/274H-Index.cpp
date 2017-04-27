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