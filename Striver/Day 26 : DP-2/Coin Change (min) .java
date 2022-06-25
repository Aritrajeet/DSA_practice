class Solution {
    public int coinChange(int[] coins, int amount) {
        
        
        int[][] dp = new int[coins.length+1][amount+1];
        
        
        for(int i=0 ; i<dp.length ;i++)
            dp[i][0] = 0;
        
        for(int i=0 ; i<dp[0].length ; i++)
            dp[0][i] = Integer.MAX_VALUE-1;        
        
        for(int i=1 ; i<dp.length ; i++)
        {
            for(int j=1 ; j<dp[0].length ;j++)
            {
                if(coins[i-1] <= j)
                    dp[i][j] = Math.min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
                
                else
                    dp[i][j] = dp[i-1][j];
                
                
            }
        }
        
               
        return dp[dp.length-1][dp[0].length-1] == Integer.MAX_VALUE-1  ? -1 : dp[dp.length-1][dp[0].length-1] ;
    }
}
