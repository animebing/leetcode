// Hash Table
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> v2f;
        int res;
        for (auto& v : nums){
            v2f[v]++;
            if (v2f[v] > nums.size()/2){
                res = v;
                break;
            }
        }
        return res;
    }
};


// the majority element must be at n/2th position in the sorting array
// nth_element(first, n, last): Rearranges the elements in the range [first,last), 
// in such a way that the element at the nth position is the element that would 
// be in that position in a sorted sequence.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int n = nums.size();
     nth_element(nums.begin(), nums.begin()+n/2, nums.end());
     return nums[n/2];
    }
};



// get a random element from nums, then determine whether it is the majority
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true){
            int idx = rand()%n;
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (nums[i] == nums[idx])
                    cnt++;
            }
            if (cnt > n/2) return nums[idx];
        }
    }
};


// Moore Voting Algorithm
// find a element different from current majority repeatedly, then left element is the majority number
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, majority;
        for (int i = 0; i < n; i++){
            if (cnt == 0){
                majority = nums[i];
                cnt = 1;
            }else{
                if (nums[i] == majority) cnt++;
                else cnt--;
            }
        }
        return majority;
    }
};