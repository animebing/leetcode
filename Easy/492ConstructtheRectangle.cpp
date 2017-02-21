// in order to guarantee L>=W, then W <= sqrt(area)
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 0, l = INT_MAX;
        for (int i = 1; i*i <= area; i++) {
            if (area % i == 0) {
                if (area/i-i < l-w) {
                    w = i;
                    l = area/i;
                }
            }
        }
        vector<int> res;
        res.push_back(l);
        res.push_back(w);
        return res;
    }
};

// based on the solution of Kenigma, https://discuss.leetcode.com/topic/76469/3ms-concise-c
// diff = area/w-w, when   1=< w <= sqrt(are), when w increases, diff decreases, so w is largest i 
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 1;
        for (int i = 1; i*i <= area; i++) {      
            if (area % i == 0) w = i;
        }
        return vector<int> {area/w, w};
    }
};


// based on the solution of beckswu, https://discuss.leetcode.com/topic/77526/3-line-c-clean-solution-with-explanation
// utilize what i said in solution 2, we begin search w from sqrt(w)
#include <cmath>
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w;
        for (w = sqrt(area); w > 0; w--)
            if (area % w == 0) break;
        return vector<int> {area/w, w};
    }
};

