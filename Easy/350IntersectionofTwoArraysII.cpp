// sort two vectors first, then use tow pointers to got the intersection 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};


// based on the solution of StefanPochmann
// use algorithm set_intersection, store in the original vector, then erase the redundant elements
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());
        return nums1;
    }
};

// based on the solution of StefanPochmann, HASHTABLE METHOD
// the fastest version, record the number of occurrence of each elements, then check whether whether these two vectors
// has common elements.
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int i:nums1) 
            cnt[i]++;
        vector<int> out;
        for (int i:nums2)
            if (cnt[i]-- > 0)   // fantastic here, whether appear and the number of appearance
                out.push_back(i);
        
        return out;
    }
};