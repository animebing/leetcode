// two pointers, sorted array
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size()-1;
        while (low < high) {
            if (numbers[low]+numbers[high] == target) return vector<int> {low+1, high+1};
            else if (numbers[low]+numbers[high] > target) high--;
            else low++;
        }
    }
};