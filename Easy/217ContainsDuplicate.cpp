// use map to record how many times a num appear, if bigger than 2, return true, or false
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> occur;
        for (int i = 0; i < nums.size(); i++){
            if (++occur[nums[i]] == 2) return true;
        }
        return false;
    }
};

// based on the solution of chammika
// use set container to contain the unique elements in vector, if size of vector and set is equal,then return false, or true 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};

// based on the solution of deck
// using unordered_map, the retrieve based on key are much faster than map
// in map, the elements are sorted by their keys, but not in unordered_map  
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        if (nums.empty()) return false;
        for (auto n : nums){
            if (++mp[n] > 1) return true;
        }
        return false;
    }
};


// based on the solution of caikehe 
// sort the vector first, then compare the adjacent elements, faster than above method
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-1; i++){
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};