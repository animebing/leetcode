// based on the solution of Freezen and explanation of ElementNotFoundException
// if a is a happy number, then the slow must catch fast at 1
// if a is not a happy number, because the sumSquare is in a set with finite values, 
// then there must be a loop if sumSquare is endless.
int sumSquare(int a){
    int res = 0, q = a;
    while (q != 0){
        res += (q%10)*(q%10);
        q /= 10;
    }
    return res;
}

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = sumSquare(slow);
            fast = sumSquare(sumSquare(fast));
            if (fast == 1) return true;
        }while(slow != fast);
        return false;
    }
};