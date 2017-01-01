// use one map to record how many times an elements appeared, another map to record the index of recent appeared
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> occu;
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++){
            if (++occu[nums[i]] > 1){
                if (i-index[nums[i]] <= k) return true;
                else index[nums[i]] = i;
            }else{
                index[nums[i]] = i;
            }
        }
        return false;
    }
};

// based on the solution of towhid 
// same idea as above, but just use one unordered_map, which is used to record to index of recent appearance of one element
// use count function to check whether the element appeared before
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++){                  
            if (index.count(nums[i]) == 1){                                // if (index.count(nums[i]) && i-index[nums[i]]<=k) return true;
                if (i-index[nums[i]] <= k) return true;                    // index[nums[i]] = i   
                else index[nums[i]] = i;
            }else index[nums[i]] = i;
        }
        return false;
    }
};


// based on the solution of lchen77 
// te check in a sliding window whose size of k+1 whether one element has occurred before
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> window;
        for (int i = 0; i < nums.size(); i++){
            if (i > k) window.erase(nums[i-k-1]);    // i-1-a+1 = k+1, so a = i-k-1
            if (!window.insert(nums[i]).second) return true;   // returning value of insert is a pair <iterator, bool>, 
        }                                                      // if the elment has in set, the  pair.second is false, otherwise true
        return false;                                          // at the same time, insert the element into the set
    }
};