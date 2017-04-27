// the same solution as H-Index I
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int h = 0;
        for (int i = citations.size()-1; i >= 0; i--) {
            if (citations[i] >= h+1) h++;
            else break;
        }
        return h;
    }
};