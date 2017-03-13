// two pointers, idx points to the last element in new array, cnt represents how many times the last element has occurred
// when cnt is larger than or equal to 2, idx stays until find an element diffrent from the element in idx
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int idx = 0;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[idx]) {
                if (cnt < 2) {  // 2 can be k
                    nums[++idx] = nums[i];
                    cnt++;
                }
            }else {
                nums[++idx] = nums[i];
                cnt = 1;
            }
        }
        //nums.resize(idx+1);
        return idx+1;
    }
};


// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/17180/3-6-easy-lines-c-java-python-ruby
// much conciser, skip first 2 elements, use i to indicate the position where to add new elemens, when a > nums[i-2], which
// means there isn't  more than 2 a in the new array    
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int a : nums) {   // 2 can be k
            if (i<2 || a>nums[i-2]) nums[i++] = a;
        }
        return i;
    }
};


// my first code is almost same as tech-wonderland.net, https://discuss.leetcode.com/topic/7673/share-my-o-n-time-and-o-1-solution-when-duplicates-are-allowed-at-most-k-times