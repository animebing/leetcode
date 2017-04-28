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


// based on the above idea, using binary search to solve it.
// ATTENTION: the case with all zeros
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (citations[mid] >= n-mid) right = mid; 
            else left = mid+1;
        }
        if (citations[left] == 0) return 0;   // ------------------------
        else return n-left;
    }
};