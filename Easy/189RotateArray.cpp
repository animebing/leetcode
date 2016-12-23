// keep the last k elements, the rotate other elements, the copy back the first elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return;
        vector<int> tmp(nums.begin()+n-k, nums.end());
        for (int i = n-k-1; i >= 0; i--){
            nums[i+k] = nums[i];
        }
           
        
        for (int i = 0; i < k; i++)
            nums[i] = tmp[i];
    }
};

// based on the solution of zhukov 
// copy the whole vector to get rid of elements overwriting
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==0 || k==0) return;
        vector<int> numsCopy(nums);
        for (int i = 0; i < n; i++)
            nums[(i+k)%n] = numsCopy[i];
    }
};

// based on the solution of zhukov
// the most concise and interesting solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;
        if (k == 0) return;
        
        // reverse the last k elements
        reverse(nums.begin()+n-k, nums.end());
        // reverse the first n-k elements
        reverse(nums.begin(), nums.begin()+n-k);
        // reverse the whole vector
        reverse(nums.begin(), nums.end());
    }
};


// start from one element, then move to corresponding position and keep the value in that position
// then move the element in that position, then repeatedly
// i can't totally understand the solution below, i know the condition in do-while is to avoid repeated loop
// but start++ does not check whether element in start++ position have moved, maybe there is no need to do it,
// but i don't know why
class Solution 
    {
    public:
        void rotate(int nums[], int n, int k) 
        {
            if ((n == 0) || (k <= 0))
            {
                return;
            }
            
            int cntRotated = 0;
            int start = 0;
            int curr = 0;
            int numToBeRotated = nums[0];
            int tmp = 0;
            // Keep rotating the elements until we have rotated n 
            // different elements.
            while (cntRotated < n)
            {
                do
                {
                    tmp = nums[(curr + k)%n];
                    nums[(curr+k)%n] = numToBeRotated;
                    numToBeRotated = tmp;
                    curr = (curr + k)%n;
                    cntRotated++;
                } while (curr != start);
                // Stop rotating the elements when we finish one cycle, 
                // i.e., we return to start.
                
                // Move to next element to start a new cycle.
                start++;
                curr = start;
                numToBeRotated = nums[curr];
            }
        }
    };

