// naive solution, maintain first max, second max and third max respectively, then update them
// at last, check whether the third max updates, if not, then return the first max
// same idea as agave in python, https://discuss.leetcode.com/topic/70613/intuitive-and-short-python-solution/2
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = (long)INT_MIN-1, second = (long)INT_MIN-1, third = (long)INT_MIN-1;  // here use long to avoid there is INT_MIN in array
        for (auto v:nums) {
            if (v >= first){  // two if statements, ugly but necessary
                if (v > first) {
                    third = second;  // updates third and second max when the first max updates
                    second = first;
                    first = v;
                }
            }
            else if (v >= second) {
                if (v > second) {
                    third = second;
                    second = v;
                }
            }
            else if (v >= third) third = v;
        }
        if (third == (long)INT_MIN-1) return first;
        else return third;
    }
};


// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/63903/short-easy-c-using-set
// http://www.cplusplus.com/reference/set/set/?kw=set and http://www.cplusplus.com/reference/set/set/insert/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> res;
        for (int v:nums) {
            res.insert(v); // return a pair, the elements in set is ascending by default, which is determined by Compare 
            if (res.size() > 3) res.erase(res.begin());
        }
        return res.size()==3 ? *res.begin() : *res.rbegin();
    }
};