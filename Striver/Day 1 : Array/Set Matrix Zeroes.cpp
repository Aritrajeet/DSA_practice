//Question: https://leetcode.com/problems/set-matrix-zeroes/

//Solution: 
class Solution {
public: //keep two vectors to store the index of element that is 0. Later update ith row and jth col to 0.
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r;
        vector<int> c;
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for (int i=0; i<r.size();i++){
            for (int j=0; j<matrix.size(); j++){
                matrix[j][c[i]] = 0;
            }
            for (int j=0; j<matrix[0].size(); j++){
                matrix[r[i]][j] = 0;
            }
        }
    }
};

//Optimized approach without extra space: If you find any 0 element at (i,j) update arr[0][j] and arr[i][0] to 0 meaning that complete row and column should be 0.
//After complete matrix traversal , traverse first col , if 0 found make that complete row 0 , same for col. 
