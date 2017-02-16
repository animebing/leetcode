// my solution, sort the array first, if all elements are equal, then stop, otherwise, increse each element but the max one
// repeat above operation
// but time limited error
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int move = 0;
        int len = nums.size();
        while (1) {
            sort(nums.begin(), nums.end());
            if (nums[0] == nums[len-1]) return move;
            for (int i = 0; i < len-1; i++) nums[i] += 1;
            move++;
        }
    }
};


// based on the solution ofStefanPochmann and KnightY, https://discuss.leetcode.com/topic/66562/simple-one-liners
// https://discuss.leetcode.com/topic/66771/what-if-we-are-not-smart-enough-to-come-up-with-decrease-1-here-is-how-we-do-it
// i am not completely understand the explaination
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long sum = 0;
        long min_v = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] < min_v) min_v = nums[i];
        }
        return sum - nums.size()*min_v;      // or return accumulate(nums.begin(), nums.end(), 0L) - (long)nums.size()*(*min_element(nums.begin(), nums.end()))
                                                                                                    // long here or not will not affect the result, why? 
    }
};