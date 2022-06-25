class Solution {
    public int minPathSum(int[][] grid) {
          
       int[][] dp = new int[grid.length][grid[0].length];
       return helper(grid , 0 , 0 , dp );
        
     }
    
    public static int helper(int[][] grid , int row , int col , int[][] dp )
    {   
        if(row == grid.length-1 && col == grid[0].length-1)
            return grid[row][col];
        
        if(row == grid.length || col == grid[0].length)
            return 300;
     
        if(dp[row][col] > 0)
            return dp[row][col];
        
        int left  =  grid[row][col] + helper(grid , row , col+1 , dp);
        int right =  grid[row][col] + helper(grid , row+1 , col , dp);
        
        
        return dp[row][col] = Math.min(left,right);
        
    }
    
    
}

