class Solution {
    public int minCost(int n, int[] cuts) {
        
        Arrays.sort(cuts);    
        int[][] dp = new int[cuts.length][cuts.length];
        return  helper(cuts , 0 , cuts.length-1 , 0  , n  , dp);
        
    }
    
    
    public static int helper(int[] cuts , int si , int ei , int i , int j , int[][] dp)
    {
        
        if(si>ei || i>=j)
         return 0;
        
        if(dp[si][ei] > 0)
            return dp[si][ei];
        
        int ans = Integer.MAX_VALUE;
        
        for(int k=si ; k<=ei ; k++)
        {
            int left  = helper(cuts , si , k-1 , i , cuts[k] , dp);
            int right = helper(cuts , k+1 , ei , cuts[k] , j , dp);
            
            ans = Math.min(left+right , ans);
        }
        
        return dp[si][ei] = ans+j-i;
    }
}
