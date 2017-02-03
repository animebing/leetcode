// naive solution, i don't use the note that the sumRange will be called many times
class NumArray {
public:
    NumArray(vector<int> nums) {
        num_vec = nums;
    }
    
    int sumRange(int i, int j) {
        long sum = 0;
        // assume that all calls are reasonable
        for (int t = i; t <= j; t++){
            sum += num_vec[t];
            
        }
        if (sum >= INT_MAX) return INT_MAX;
        else if (sum <= INT_MIN) return INT_MIN;
        else return sum;
    }
private:
    vector<int> num_vec;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


// based on the solution of  jianchao.li.fighter
// compute the accumulation of the array in advance
class NumArray {
public:
    NumArray(vector<int> nums) {
        accu.push_back(0);
        for (auto num:nums){
            accu.push_back(accu.back()+num);
        }
    }
    
    int sumRange(int i, int j) {
        return accu[j+1]-accu[i];
    }
private:
    vector<int> accu;
};

// based on the solution of rantos22
// use the build-in function partial_sum 
class NumArray {
public:
    NumArray(vector<int> nums):accu(nums.size()+1, 0) {
        partial_sum(nums.begin(), nums.end(), accu.begin()+1);
    }
    
    int sumRange(int i, int j) {
        return accu[j+1]-accu[i];
    }
private:
    vector<int> accu;
};