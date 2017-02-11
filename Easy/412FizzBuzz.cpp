// process each number one by one
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i%3==0 && i%5==0) res.push_back("FizzBuzz");
            else if (i%3==0) res.push_back("Fizz");
            else if (i%5==0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
        
    }
};

// based on the solution of lalamida, https://discuss.leetcode.com/topic/63774/c-solution-3ms 
// interesting one
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; i++) {
            if (i%3 == 0) res[i-1] += "Fizz";
            if (i%5 == 0) res [i-1] += "Buzz";
            if (res[i-1] == "") res[i-1] += to_string(i);
        }
        return res;
    }
};

// the python solution of StefanPochmann, https://discuss.leetcode.com/topic/63876/python-golf, is very concise
