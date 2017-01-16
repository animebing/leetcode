// based on the solution of hyzhang 
// move all nonzero elements to front, use j to record the position of zero elements
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)   nums[j++] = nums[i];
        
        for (; j < nums.size(); j++) 
            nums[j] = 0;
    }
};

// based on the solution of piyush121 
// find the first nonzero element, then swap the nonzero element and zero element, increase the position of zero element
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        while (ptr<nums.size() && nums[ptr])
            ptr++;
        
        for (int i = ptr+1; i < nums.size(); i++)
            if (nums[i]) swap(nums[ptr++], nums[i]);  // swap(T &a, T &b)
    }
};


// based on the solution of jaewoo 
// almost same as above one, but there will be some waste when nums are all nonzero 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, last = 0; i < nums.size(); i++)
            if (nums[i]) swap(nums[last++], nums[i]);
    }
};

// based on the solution of zhaohui0 
// swap only find the first zero element, equivalent with the 2nd solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, last = 0; i < nums.size(); i++)
            if (nums[i]){
                if (last != i) swap(nums[last], nums[i]);
                last++;
            }
    }
};