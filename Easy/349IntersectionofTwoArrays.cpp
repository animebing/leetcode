// naive solution, check whether each element in nums1 is existed in nums2, is so, check whether it is existed in res
// but really slow
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) return res;
        for (int i = 0; i < nums1.size(); i++) {
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()){
                if (find(res.begin(), res.end(), nums1[i]) == res.end())
                    res.push_back(nums1[i]);
            }
        }
        return res;
    }
};

// based on the solution of Kenigma 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());  // get array with unique elements
        vector<int> res;
        for (auto a:nums2) { 
            if (m.count(a)){  // 0 or 1
                res.push_back(a);
                m.erase(a);  // avoid the duplication of a in nums2
            }
        }
        return res;
    }
};

// based on the solution of Kenigma 
// use two unordered_set, slower than use one unordered_set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m1(nums1.begin(), nums1.end());
        unordered_set<int> m2(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto a:m2) {
            if (m1.count(a)){
                res.push_back(a);
            }
        }
        return res;
    }
};

// based on the solution of StefanPochmann
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a:nums2) {
            if (m.erase(a)) {  // almost same as the 2nd solution, but just use erase, slower than 2nd solution
                res.push_back(a);
            }
        }
        return res;
    }
};

// based on the solution of wizowizo
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while (i<nums1.size() && j<nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                if (!res.size() || res.back()!=nums1[i]) res.push_back(nums1[i]);  // the res is empty or the element isnot existed in res
                i++;
                j++;
            }
        }
        return res;
    }
};