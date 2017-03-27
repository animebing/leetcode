// in each gas station, add all gas, if the left gas is less than the cost, then fails
// but time limit exceeded
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty()) return -1;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int left = 0;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                left += gas[(i+j)%n];
                if (left < cost[(i+j)%n]) {
                    flag = false;
                    break;
                }
                left -= cost[(i+j)%n];
            }
            if (flag) return i;
        }
        return -1;
    }
};

// based on the solution of XBOX360555, https://discuss.leetcode.com/topic/39755/proof-of-if-total-gas-is-greater-than-total-cost-there-is-a-solution-c
// perfect proof, assuming that \sum_{i=0}^{n-1} gas[i]-cost[i] >= 0, then if exists idx such that \sum_{i=0}^{idx} gas[i]-cost[i] is minimum, 
// then idx+1 is the staring position 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty()) return -1;
        int sum_min = INT_MAX;
        int left = 0, n = gas.size(), start;
        for (int i = 0; i < n; i++) {
            left += gas[i]-cost[i];
            if (left < sum_min) {
                sum_min = left;
                start = i+1;
            }
        }
        return (left >= 0) ? (start%n) : -1;
    }
};


