// naive and lazy idea, create a new vector, compare two vector from beginning
// add the remaining elements to the new vector, then assign the new vector to nums1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m+n, 0);
        int i = 0, j = 0, idx = 0;
        while(i<m && j<n){
            if (nums1[i] < nums2[j]){
                tmp[idx++] = nums1[i++];
            }else{
                tmp[idx++] = nums2[j++];
            }
        }
        if (i == m){
            while(j < n){
                tmp[idx++] = nums2[j++];
            }
        }else{
            while (i < m){
                tmp[idx++] = nums1[i++];
            }
        }
        nums1 = tmp;  // O(n)
    }
};


// Based on the solution of LHearen and deck 
// This code relies on the simple observation that once all of the numbers from nums2 have been merged into nums1, the rest of the numbers
//in nums1 that were not moved are already in the correct place.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, cur = m+n-1;
        while (i>=0 && j>=0) nums1[cur--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        while (j >= 0) nums1[cur--] = nums2[j--];
    }
};

/*
or just one loop
while (j >= 0){
    nums1[cur--] = i>=0 && nums1[i]>nums2[j] ? nums1[i--] : nums2[j--]
}
*/