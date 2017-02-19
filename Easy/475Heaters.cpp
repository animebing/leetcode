// based on the solution of yanzhan2, https://discuss.leetcode.com/topic/71520/simple-c-solution
// for each house, find the heater nearest to it, and compute the distance, then the minimum radius is the maximum of all distance
// i am a little frustrated on this solution, i am confused by the minimum in a sorting array and the "<=" used in while loop
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int idx = 0;
        int res = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (idx+1<heaters.size() && (abs(houses[i]-heaters[idx+1])<=abs(houses[i]-heaters[idx]))) idx++;
            res = max(res, abs(houses[i]-heaters[idx]));
        }
        return res;
    }
};