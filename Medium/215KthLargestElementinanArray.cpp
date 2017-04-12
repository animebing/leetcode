// use something in quick sort, the partion function and iterative implementation
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = n-1;
        int idx = partation(nums, start, end);
        while (idx != k-1) {
            if (idx > k-1) {
                end = idx-1;
                idx = partation(nums, start, end);
            } else {
                start = idx+1;
                idx = partation(nums, start, end);
            }
        }
        return nums[idx];
    }
private:
    int partation(vector<int> &nums, int start, int end) {
        if (start == end) return start;
        int mid = start + (end-start)/2;
        swap(nums[start], nums[mid]);
        int pivot = start+1;
        for (int i = start+1; i <= end; i++) {
            if (nums[i] > nums[start]) swap(nums[pivot++], nums[i]);
        }
        pivot--;
        swap(nums[start], nums[pivot]);
        return pivot;
    }
};