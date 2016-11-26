
// when the first duplicate value occurs and record it, when different value occurs, then remove all duplicate values
// attention: the list is over, but the duplicatd values are still there
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0 || nums.size()==1) return nums.size();
        vector<int>::iterator iter = nums.begin()+1, start;
        bool flag = true;
        int base = nums[0];
        while (iter < nums.end()){
            if (*iter==base){
                if (flag) {
                    start = iter;
                    flag = !flag;
                }
            }
            else if (!flag) {
                iter = nums.erase(start, iter);
                flag = !flag;
            }
            base = *iter;
            iter++;
            if (iter==nums.end() && !flag) iter = nums.erase(start, iter);
        }
        
        return (int)nums.size();
    }
};


// excelent work
// it doesnot use erase method, just overwrite the duplicate values, so cool
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = !nums.empty();
        for (auto n : nums){
            if (n != nums[i-1]) nums[i++] = n;
        }
        // if we need to output the list, we need "nums.resize(i)";
        return i; 
    }
};