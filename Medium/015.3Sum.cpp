// based on the solution ofkun3, https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments
// sort the array first, then choose one element, find the other two elements with 2sum using two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            if (nums[i] > 0) break;
            int target = -nums[i];
            int front = i+1, back = nums.size()-1;
            while (front < back) {
                int tmp = nums[front]+nums[back];
                if (tmp < target) front++;
                else if (tmp > target) back--;
                else {
                    vector<int> vec {nums[i], nums[front], nums[back]};
                    res.push_back(vec);
                    while (front+1<back && nums[front+1]==nums[front]) front++;  // use this to remove possible duplicate solution
                    front++;
                    while (front < back-1 && nums[back-1]==nums[back]) back--;
                    back--;
                }
            }
            while (i+1<nums.size() && nums[i+1]==nums[i]) i++; // use this to remove possible duplicate solution 
            i++; 
        }
        return res;
    }
};


// based on the solution of TigerHunter, https://discuss.leetcode.com/topic/15291/20-lines-68ms-c-solution-used-two-pointers-similar-to-2sum
// make more check 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            if (nums[i] > 0) break;
            int target = -nums[i];
            int front = i+1, back = nums.size()-1;
            while (front < back) {
                int tmp = nums[front]+nums[back];
                if (tmp < target) {
                    front++;
                    while (front < back && nums[front]==nums[front-1]) front++;  // -----------------------------------
                }
                else if (tmp > target) {
                    back--;
                    while (front < back && nums[back]==nums[back+1]) back--; // -----------------------------------------
                }
                else {
                    vector<int> vec {nums[i], nums[front], nums[back]};
                    res.push_back(vec);
                    front++;
                    while (front<back && nums[front]==nums[front-1]) front++;
                    back--;
                    while (front < back && nums[back]==nums[back+1]) back--;
                }
            }
            i++;
            while (i<nums.size() && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};