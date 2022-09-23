// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int r, int c){
        if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c] == 0){
            return 0;
        }
        // cout<<r<<" "<<c<<endl;
        grid[r][c] = 0;
        return 1 + dfs(grid,r+1,c) + dfs(grid,r,c+1) + dfs(grid,r-1,c) + dfs(grid,r,c-1);   // This will calculate the area 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if(grid[i][j] == 1){
                    ans = max(ans,dfs(grid,i,j));
                }
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};
