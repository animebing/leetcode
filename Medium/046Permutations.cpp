// backtracking inspired by combination sum
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> flag(nums.size(), false);
        vector<int> com;
        helper(nums, res, com, flag);
        return res;
    }
private:
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> com, vector<bool> &flag) {
        if (find(flag.begin(), flag.end(), false) == flag.end()) {
            res.push_back(com);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (flag[i] == false) {
                com.push_back(nums[i]);
                flag[i] = true;
                helper(nums, res, com, flag);
                flag[i] = false;
                com.pop_back();
            }
        }
    }
};

// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15218/easy-solution-using-code-in-nextpermutation-can-be-used-in-permutations-ii-without-modification
// use nextPermutation to generate all permutation until the first one is generated again
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> res;
        //sort(num.begin(), num.end()); // sort is not necessary
        res.push_back(num);
        vector<int> tmp(num);
        while (1) {
            tmp = nextPermutation(tmp);
            if (tmp == num) break;
            res.push_back(tmp);
        }
        return res;
    }
private: 
    vector<int> nextPermutation(vector<int> num) {
        int n = num.size();
        int k = -1;
        for (int i = n-1; i >= 1; i--) {
            if (num[i-1] < num[i]) {
                k = i-1;
                break;
            }
        }
        if (k == -1) {
            reverse(num.begin(), num.end());
            return num;
        }
        int l;
        for (int i = n-1; i > k; i--) {
            if (num[i] > num[k]) {
                l = i;
                break;
            }
        }
        swap(num[k], num[l]);
        reverse(num.begin()+k+1, num.end());
        return num;
    }
};


// the order of generated permutation is different in above two methods