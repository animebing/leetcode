// first I think how to generate all permutation, then I find for a give permutation, compare from the last digit, when current digit is larger
// than the previous one, then the previous one should change to another digit which is larger than it and closest to it
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int n = nums.size();
        for (int i = n-1; i>=1; i--) {
            if (nums[i] > nums[i-1]) {  // the current one is larger than the previous one
                for (int j = n-1; j >= i; j--) {
                    if (nums[j] > nums[i-1]) { // find one which is larger than it 
                        swap(nums[j], nums[i-1]);
                        break;
                    }
                }
                sort(nums.begin()+i, nums.end());   // reverse is more reasonable than sort, bacause all elements are in descending order
                return;                             // it is okay to reverse it 
            }
        }
        sort(nums.begin(), nums.end());
    }
};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15216
// /a-simple-algorithm-from-wikipedia-with-c-implementation-can-be-used-in-permutations-and-permutations-ii
// same idea as above, but good explanation and implementation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int n = nums.size();
        int k = -1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {   // -----------------------------------
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = 0;
        for (int i = n-1; i > k; i--) {
            if (nums[i] > nums[k]) {   //------------------------------
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
};

// in the solution of StefanPochmann, https://discuss.leetcode.com/topic/19264/1-4-11-lines-c
// there are many algorithm in c++ to implement this function

1. next_permutation
2. is_sorted_until  upper_bound, reverse