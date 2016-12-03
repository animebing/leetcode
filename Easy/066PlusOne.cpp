// my own code, almost the same as below
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        for (int i = digits.size()-1; i >= 0; i--){
            if (digits[i] <= 8){
                result[i] += 1; 
                return result;
            }else result[i] = 0;
        }
        //vector<int>::iterator iter = result.begin();
        //result.insert(iter, 1);
        result.insert(result.begin(), 1);
        return result;
    }
};


// Based on the solution of zezedi
// this code is really cool, especially these two lines: digits[0] = 1; digits[i]++;
// the author makes full use of the setup of the problem
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0  ; i--){
            if (digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};


// Based on the solution of StefanPochmann
// this is totally concise, excellent
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size(); i--; digits[i] = 0){
            if (digits[i]++ < 9) return digits;
        }
        digits[0]++;
        digits.push_back(0);
        return digits;
    }
};
