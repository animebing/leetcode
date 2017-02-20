// based on the solution of shanjit and bailehang, https://discuss.leetcode.com/topic/75461/simple-c-solution-with-easy-explanation/2
// really simple, but i don't think of it, i am thinking when to update the max, but here update every time with loop
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int sum = 0;
        for (int v:nums) {
            if (v) sum++;
            else sum = 0;
            if (sum > max) max = sum;
        }
        return max;
    }
};

// based on the solution of dehuaguo-gmail-com, https://discuss.leetcode.com/topic/75451/concise-c-solution
// almost the same idea as above
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int sum = 0;
        for (int v:nums) {
            if (v){
                sum++;
                if (sum > max) max = sum;
            }else sum = 0;
        }
        return max;
    }
};

// based on the same idea of jasonshieh, https://discuss.leetcode.com/topic/75522/c-_ac
// this is the first one i will think of, but i don't implement it
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int sum = 0;
        for (int v:nums) {
            if (v) sum++;
            else {
                if (sum > max) max = sum;
                sum = 0;
            }
        }
        return sum>max ? sum : max;   // we can append one more 1 in nums to return max directly
    }
};