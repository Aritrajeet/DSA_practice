class Solution {
    public boolean canPartition(int[] nums) {
        
        int sum = 0;
        
        for(int val : nums)
            sum += val;
        
        if(sum % 2 == 1)
            return false;
        else
            sum = sum/2;
        
        boolean[][] dp = new boolean[nums.length+1][sum+1];
        
        for(int i=0 ; i<dp.length ; i++)
            dp[i][0] = true;
        
        for(int i=1 ; i<dp.length ; i++)
        {
            for(int j=1 ; j<dp[0].length ;j++)
            {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                
                else
                    dp[i][j] = dp[i-1][j];
                    
                
            }
        }
        
        return dp[dp.length-1][dp[0].length-1];
        
        
    }
}
