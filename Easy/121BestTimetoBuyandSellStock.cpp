class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = (int) prices.size();
        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                int tmp = prices[j]-prices[i];
                if (tmp > 0){
                    if (tmp > profit) profit = tmp;
                }
            }
        }
        return profit;
    }
};


// Based on the solution of anish19 
// update the minimum and keep the maximum profit until now
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minValue = INT_MAX;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < minValue) minValue = prices[i];
            if (prices[i]-minValue > profit) profit = prices[i]-minValue;
        }
        return profit;
    }
};


// Based on the solution of 1216114309zpf 
// almost the same idea as above, but different implementation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, sumV = 0;
        for (int i = 1; i < prices.size(); i++){
           sumV += prices[i]-prices[i-1];    // record the profit relative to the minimum
           if (sumV < 0) sumV = 0;  // update the mininum
           if (sumV > profit) profit = sumV;
        }
        return profit;
    }
};