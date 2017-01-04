// 
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area_1 = (C-A)*(D-B);
        int area_2 = (G-E)*(H-F);
        //cout << area_1 << endl;
        //cout << area_2 << endl;
        long p_1, p_2, q_1, q_2, cross;  // not int here, because the subtraction below is underflow
        p_1 = (E>A)?E:A;                 // this is not a good solution,but just work
        p_2 = (F>B)?F:B;
        q_1 = (C<G)?C:G;
        q_2 = (D<H)?D:H;
        //cout << p_1 << " " << p_2 << endl;
        //cout << q_1 << " " << q_2 << endl;
        //cout << INT_MAX << endl;
        if (q_1-p_1<0 || q_2-p_2<0) cross = 0;
        else cross = (q_1-p_1)*(q_2-p_2);
        return area_1+area_2-cross;
    }
};


// based on the solution of ManuelP 
// this solution is very clever to deal with right and top with max operation,
// which avoid the overflow or underflow caused by subtraction
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(E, A), right = max(min(C, G), left);
        int bottom = max(B, F), top = max(min(D, H), bottom);
        return (C-A)*(D-B)+(G-E)*(H-F)-(right-left)*(top-bottom);
    }
};

// In Euclidean plane geometry, a rectangle is any quadrilateral with four right angles from explanation of StefanPochmann based on wikipedia