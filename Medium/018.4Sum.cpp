// the same method as 3Sum, but here fix two number, then find the oher two number, O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>> {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());  // sort is most important thing
        for (int i = 0; i < nums.size()-1;) {
            for (int j = i+1; j < nums.size();) {
                int front = j+1, back = nums.size()-1;
                while (front < back) {
                    int sum = nums[i]+nums[j]+nums[front]+nums[back];
                    if (sum < target) {
                        front++;
                        while (front<back && nums[front]==nums[front-1]) front++;
                    }else if (sum > target) {
                        back--;
                        while (front<back && nums[back]==nums[back+1]) back--;
                    }else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[front], nums[back]});
                        front++;
                        while (front<back && nums[front]==nums[front-1]) front++;
                        back--;
                        while (front<back && nums[back]==nums[back+1]) back--;
                    }
                }
                j++;
                while (j<nums.size() && nums[j]==nums[j-1]) j++;
            }
            i++;
            while (i<nums.size()-1 && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};


// based on the solution of cx1992, https://discuss.leetcode.com/topic/28641/my-16ms-c-code
// the same ider as above, but use many check to do pruning work 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return vector<vector<int>> {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++) {
            while (i>0 && nums[i]==nums[i-1]) i++;
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;  // --------------------------------
            if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue; // --------------------------------
            for (int j = i+1; j < n-2; j++) {
                while (j>i+1 && nums[j]==nums[j-1]) j++;
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;  // --------------------------------
                if (nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue; // --------------------------------
                int front = j+1, back = n-1;
                while (front < back) {
                    int sum = nums[i]+nums[j]+nums[front]+nums[back];
                    if (sum < target) {
                        front++;
                        while (front<back && nums[front]==nums[front-1]) front++;
                    }else if (sum > target) {
                        back--;
                        while (front<back && nums[back]==nums[back+1]) back--;
                    }else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[front], nums[back]});
                        front++;
                        while (front<back && nums[front]==nums[front-1]) front++;
                        back--;
                        while (front<back && nums[back]==nums[back+1]) back--;
                    }
                }
            }
        }
        return res;
    }
};


// ATTENTION HERE, I JUST ROMOVE TWO CHECKING AT THE END OF THE FIRST AND TWO LOOP, BUT "time limit exceed", I CAN'T UNDERSTAND WHY
// BELOWE IS MY CODE, WHICH DOESN'T ACCEPT
// based on the solution of cx1992, https://discuss.leetcode.com/topic/28641/my-16ms-c-code
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return vector<vector<int>> {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3;) {
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
            for (int j = i+1; j < n-2;) {
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if (nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;
                int front = j+1, back = n-1;
                while (front < back) {
                    int sum = nums[i]+nums[j]+nums[front]+nums[back];
                    if (sum < target) {
                        front++;
                        while (front<back && nums[front]==nums[front-1]) front++;
                    }else if (sum > target) {
                        back--;
                        while (front<back && nums[back]==nums[back+1]) back--;
                    }else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[front], nums[back]});
                        front++;
                        while (front<back && nums[front]==nums[front-1]) front++;
                        back--;
                        while (front<back && nums[back]==nums[back+1]) back--;
                    }
                }
                j++;
                while (j<n-2 && nums[j]==nums[j-1]) j++;
            }
            i++;
            while (i<n-3 && nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};