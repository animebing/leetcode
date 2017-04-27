// naive solution, O(nlogn) for sorting, O(n) for finding the missing number, which doesn't meet the requirment of the question
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1-nums[0];
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) return 0;
        if (nums[n-1] != n) return n;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i]-nums[i-1] != 1) return nums[i]-1;
    }
};



// based on the solution of mo10, https://discuss.leetcode.com/topic/24535/4-line-simple-java-bit-manipulate-solution-with-explaination
// the range of complete numbers is [0, n], so for all index and existing numbers, do xor operation, the not missing number will 
// be deleted, then the result is the missing number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, i;
        for (i = 0; i < nums.size(); i++) res = res ^ i ^ nums[i];
        return res^i;
    }
};


// based on the solution of annieqt, https://discuss.leetcode.com/topic/24535/4-line-simple-java-bit-manipulate-solution-with-explaination/3
// first add all number in [0, n], then subtract the sum of all elements in array, then the left is the missing one	
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) res += i-nums[i];
        return res;
    }
};



// based on the solution of mingjun, https://discuss.leetcode.com/topic/23427/3-different-ideas-xor-sum-binary-search-java-code
// sort the array first, then do binary search. the point here is that, if one element is not missing, then nums[idx] = idx
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();   // right is n here, tricky part
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > mid) right = mid;  // the missing element is in left part including mid
            else left = mid+1; // only nums[mid] = mid, then the missing part is in right part excluding mid
        }
        return left;
    }
};