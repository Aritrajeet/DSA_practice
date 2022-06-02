//If it was a square matrix then we can directly do it using swap of upper triangular matrix with lower one.
//But here it is m X n matrix. So we create a new matrix of size n X m and do new_matrix[i][j] = old_matrix[j][i]
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        for (int i=0;i<m; i++){
            for (int j=0; j<n; j++){
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
