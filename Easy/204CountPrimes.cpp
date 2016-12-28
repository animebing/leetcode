// go through all numbers less than n to determine whether it is a prime, n^1.5 complexity
bool isPrime(int n){
    if (n <= 1) return false;
    float bound = sqrt(n);
    for (int i = 2; i <= bound; i++){    // i*i <= n
        if (n%i == 0) return false;
    }
    return true;
}
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 1; i < n; i++){
            if (isPrime(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};


// based on hint, my version
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> mark(n-1, true);
        mark[0] = false;
        for (int i = 2; i < sqrt(n); i++){
            for (int j = i*i; j < n; j+=i)
                mark[j-1] = false;
        }
        int cnt = 0;
        for (int i = 0; i < n-1; i++){
            if (mark[i]) cnt++;
        }
        return cnt;
    }
};


// based on the hint, hint version
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mark(n);
        for (int i = 2; i < n; i++) mark[i] = true;
        for (int i = 2; i*i < n; i++){
            if (!mark[i]) continue;     // important step
            for (int j = i*i; j < n; j+=i)
                mark[j] = false;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (mark[i]) cnt++;
        return cnt;
    }
};

// based on the solution of deck 
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mark(n);
        for (int i = 2; i < n; i++) mark[i] = true;
        for (int i = 2; i*i < n; i++){
            if (mark[i]){
                for (int j = i*i; j < n; j+=i)
                    mark[j] = false;    
            }
        }
        return count(mark.begin(), mark.end(), true);
    }
};