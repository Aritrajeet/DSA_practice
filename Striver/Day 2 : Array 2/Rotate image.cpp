//Question: https://leetcode.com/problems/rotate-image/

//Solution:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose the matrix
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) continue;
                else if (i<j){
                    swap(matrix[i][j],matrix[j][i]);      //transpose the matrix (row becomes col and col becomes row)
                }
            }
        }
        
        for (int i=0; i<n; i++){
            for (int j=0; j< n/2; j++){
                swap(matrix[i][j],matrix[i][n-j-1]);      //Now, reverse the columns by swapping pairwise
            }
        }
    }
};
