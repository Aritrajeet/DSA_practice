//Question: https://leetcode.com/problems/minimum-path-sum/

//Solution:
class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int t[m+1][n+1];
        for (int i=0; i<m+1; i++){
            t[i][0] = 0;
        }
        for (int j=0; j<n+1; j++){
            t[0][j] = 0;
        }
        int r_sum=0;
        for (int i=1; i<m+1; i++){
            r_sum += nums[i-1][0];
            t[i][1] = r_sum;    
        }
        int c_sum=0;
        for (int j=1; j<n+1; j++){
            c_sum += nums[0][j-1];
            t[1][j] = c_sum;
        }
        for (int i=2; i<m+1; i++){
            for (int j=2; j<n+1; j++){
                t[i][j] = nums[i-1][j-1] + min(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
    }
};
