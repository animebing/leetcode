// brute force, but time limit exceeded
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size()-1; i++) {
             for (int j = i+1; j < height.size(); j++) {
                 int tmp = (j-i)*min(height[i], height[j]);
                 if (tmp > res) res = tmp;
             }
        }
        return res;
    }
};


// based on the solution of StefanPochmann, https://discuss.leetcode.com/topic/16754/simple-and-fast-c-c-with-explanation
// begin from the first and last line, then to hold more water, the following two lines must support higher height
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, (j-i)*h);
            while (height[i]<=h && i<j) i++;  // find two lines supporting higher height
            while (height[j]<=h && i<j) j--;
        }
        return res;
    }
};