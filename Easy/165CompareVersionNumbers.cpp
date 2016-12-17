// Based on the solution of ArthurSonzogni 
// first replace '.' with ' ', then istringstream, >> 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (auto& w:version1) if (w=='.') w = ' ';
        for (auto& w:version2) if (w=='.') w = ' ';
        istringstream s_1(version1), s_2(version2);
        int n_1, n_2;
        while (1){
            if (!(s_1>>n_1)) n_1 = 0;
            if (!(s_2>>n_2)) n_2 = 0;
            if (!s_1 && !s_2) return 0;
            if (n_1 > n_2) return 1;
            if (n_1 < n_2) return -1;
        }
    }
};