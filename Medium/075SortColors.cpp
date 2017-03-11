// just like sorting a string which consists of 26 letters, so we can count the number of each letter, then get them one by one
// here we can do this again, because there is only 0, 1, 2 in the array, so we can compute the number of them respectively
// here is two pass, O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        vector<int> cnt(3, 0);
        for (auto a:nums) cnt[a]++;
        int k = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < cnt[i]; j++) nums[k++] = i;
        }
    }
};

// based on the solution of yidawang, https://discuss.leetcode.com/topic/5422/share-my-at-most-two-pass-constant-space-10-line-solution
// put all 0 to the left and put all 2 to the right
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        int zero = 0, two = nums.size()-1;  // all elements left to zero is 0 and all elements right to two is 2
        for (int i = 0; i <= two; i++) {
            while (nums[i]==2 && i<two) swap(nums[i], nums[two--]); // after swapping, check whether new nums[i] is 2, stop until not
            while (nums[i]==0 && i>zero) swap(nums[i], nums[zero++]); // same as above line
        }
    }
};

// based on the solution of shichaotan, https://discuss.leetcode.com/topic/6968/four-different-solutions
// just like insertion sorting, all elements before nums[i] is sorted, but here the question is special, 
// there are only 3 distinct numbers, so here define n0, n1, n2 to represent the idx of the last 0, 1, 2 in the sorted sequence

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        int n0 = -1, n1 = -1, n2 = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] == 0) {
                nums[++n2] = 2;
                nums[++n1] = 1;
                nums[++n0] = 0;
            }else if (nums[i] == 1) {
                nums[++n2] = 2;
                nums[++n1] = 1;
            }else nums[++n2] = 2;
        }
        
    }
};