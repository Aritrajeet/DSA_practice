class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m;
        while(low < high){
            int mid = low + (high - low)/2;
            int row = mid/m;
            int col = mid%m;
            //cout<<matrix[row][col]<<" ";
            if(target == matrix[row][col]){
                return true;
            }
            else if(target > matrix[row][col]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return false;
    }
};
