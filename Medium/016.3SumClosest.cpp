// based on the solution of asbear, https://discuss.leetcode.com/topic/17215/c-solution-o-n-2-using-sort
// almost the same as 3Sum, but for each try, we need to update the closest res
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size();) {
            int front = i+1, back = nums.size()-1;
            while (front < back) {
                int tmp = nums[i]+nums[front]+nums[back];   // --------------------------------------
                if (abs(tmp-target) < abs(res-target)) res = tmp;
                if (tmp < target) {
                    front++;
                    while (front<back && nums[front]==nums[front-1]) front++;
                }else if (tmp > target) {
                    back--;
                    while (front<back && nums[back]==nums[back+1]) back--;
                }else return tmp;
            }
            i++;
            while (i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};