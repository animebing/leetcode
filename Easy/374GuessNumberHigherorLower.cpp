// pay attention to the discussion of Nakanu and following discussion of StefanPochmann
// first i know i need to use binary search, but i don't kown when to use the guess API
// because i think the number we are guessing should be given, later i got it, which is just like
// the game, we don't need to know the number, when we are guessing, the game master will give us
// whether your guess is right or not. guess API is like the game master, and middle is the guess we give

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (1) {
            int middle = low+(high-low)/2;
            if (guess(middle) == 0) return middle;
            else if (guess(middle) == 1) low = middle+1;
            else high = middle-1;
        }
    }
};