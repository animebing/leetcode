// just like before, use the left value to override the value we want to remove

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (auto value : nums){
            if (value != val) nums[i++] = value;
        }
        return i;
    }
};