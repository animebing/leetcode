// based on the solution of Agramatir
// dynamic programming with lookup table
// caution: "can win, not always win"
// 1->w, 2->w, 3->w, 4->l, 5->w(remove 1), 6->w(remove 2), 7->w(remove 3), 8->l, 9->w(remove 1), 10->w(remove 2), 11->w(remove 3)
// if n%4 != 0, you can(not always) win
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};