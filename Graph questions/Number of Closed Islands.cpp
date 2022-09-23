// https://leetcode.com/problems/number-of-closed-islands/


class Solution {
public:
    bool dfs(vector<vector<int>> &grid, int row, int col){
        if(row<0 or col<0 or row>= grid.size() or col>= grid[0].size()){    // this is false case since island should be surrounded by land so 0 cant be in edges
            return false;
        }
        if(grid[row][col] == 1){       // This is true case indicating the island ends somewhere
            return true;
        }
        grid[row][col] = 1;     //  mark as water so that we dont consider it again
      
        //*** return dfs(grid,row+1,col) and dfs(grid,row,col+1) and dfs(grid,row-1,col) and dfs(grid,row,col-1); 
        // This wont work since if one is false others wont work and we wont be able to mark other nodes as 1. So some nodes will remain in the center and make themselves island which is wrong
        bool b1 = dfs(grid,row+1,col);
        bool b2 = dfs(grid,row-1,col);
        bool b3 = dfs(grid,row,col+1);
        bool b4 = dfs(grid,row,col-1);
        return b1 and b2 and b3 and b4;   // This will allow the dfs calls to execute first and then later decide if it is an island
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j))
                        count++;
                }
            }
        }
        return count;
    }
};
