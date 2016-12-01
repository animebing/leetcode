// with recursion, the idea is simple, but time limit exceeded
void branch(int cur, int top, int &cnt){
    if (cur == top){
        cnt++;
        return;
    }
    if (cur+1 <= top) branch(cur+1, top, cnt);
    if (cur+2 <= top) branch(cur+2, top, cnt);
}

class Solution {
public:
    int climbStairs(int n) {
        int cnt = 0;
        branch(0, n, cnt);
        return cnt;
    }
};



// Here step_1 is the way along which the last one is one step, step_2 means the last one is two step
// when we consider the next stair, it can be formed by the previous way 
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int step_1 = 1, step_2 = 0;
        int cnt;
        while (n >= 2){
            int tmp = step_1 + step_2;
            step_2 = step_1;
            step_1 = tmp;
            cnt = step_1 + step_2;
            n--;
        }
        return cnt;
    }
};


// Based on the solution of vogelkaka 
/* Array 'steps' stands for how many distinct ways to climb to each level 
(index from 0, so 0 means level 1, 1 means level 2 and so on.... ). It's trivial 
to know it has 1 distinct way to climb to stair 1 , and 2 distinct ways to climb to stair 2 . 
For stair level n (n>=3) , you can either (1) climb to stair n-2 , and climb 2 more steps to reach n , 
OR (2) climb to stair n-1, and climb 1 more step to reach n. That said , steps[n]=steps[n-1]+steps[n-2]. 
In another word, the number of distinct ways to reach level n is the sum of number of distinct ways to reach level n-1 and n-2.
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n, 0);
        result[0] = 1; 
        result[1] = 2;
        for (int i = 2; i < n; i++)
            result[i] = result[i-1] + result[i-2];
        
        return result[n-1];
    }
};


// Top-down: recursion + memorization. Based on the solution of vogelkaka 
class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if (cache.find(n) != cache.end()) return cache[n];
        int result;
        if (n == 1) result = 1;
        if (n == 2) result = 2;
        if (n >= 3) result = climbStairs(n-2)+climbStairs(n-1);
        cache[n] = result;
        return result;
    }
};