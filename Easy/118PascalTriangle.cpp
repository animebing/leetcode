class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i = 0; i < numRows; i++){
            vector<int> vec(i+1, 1);                                  // pascal.push_back(vector<int>(i+1, 1));
            for (int j = 1; j < i; j++){                              // for (int j = 1; j < i; j++)
                vec[j] = pascal[i-1][j-1]+pascal[i-1][j];             //    pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
            }
            pascal.push_back(vec);
        }
        return pascal;
    }
};


// Based on the solution of Ximin.Z 
// just using one vector
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> vec;
        for (int i = 0; i < numRows; i++){
            vec.push_back(1);  // make left and right end be 1
            for (int j = i-1; j > 0; j--) vec[j] = vec[j-1]+vec[j];   // compute from right to left, there will be wrong from left to right
            pascal.push_back(vec);
        }
        return pascal;
    }
};