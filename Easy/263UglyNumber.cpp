// based on the solution of StefanPochmann
// repeated divided by 2, 3 and 5 until it cannot be proceeded, then check whether the remainder is equal to 1
// if it is not equal to 1, then at least it is 7 
class Solution {
public:
    bool isUgly(int num) {
        if (num > 0){
            for (int i = 2; i < 6; i++)  // 4 here is just to make code simpler, because 4 will be directly skip, 4 = 2*2
                while (num % i == 0)
                    num /= i;;
        }
        return num == 1;
    }
};