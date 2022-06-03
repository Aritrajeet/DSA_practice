//brute force approach -TLE
class NumMatrix {
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i=0; i< matrix.size(); i++){
            vector<int> temp;
            for (int j=0; j< matrix[0].size(); j++){
                temp.push_back(matrix[i][j]);
            }
            ans.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i=row1; i<=row2; i++){
            for (int j=col1; j<=col2; j++){
                sum += ans[i][j];
            }
        }
        return sum;
    }
};
