//Question: https://leetcode.com/problems/search-a-2d-matrix/

//Solution: Brute force - Search first col then select the desired row and do linear search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        for (int i=0; i<matrix.size(); i++){
            if (matrix[i][0] > target){
                row = i-1;
                break;
            }
        }
        if (row == -1) row = matrix.size() - 1;
        for (int j=0; j<matrix[0].size(); j++){
            if (matrix[row][j] == target)
                return true;
        }
        return false;
    }
};

//Optimal solution : Binary search - Consider whole matrix as a 1-D array and apply binary search. Then generate the row and col index for x through x / no_of_cols and x % no_of_cols.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m;
        while(low < high){
            int mid = low + (high - low)/2;
            int row = mid/m;    //observation
            int col = mid%m;
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
