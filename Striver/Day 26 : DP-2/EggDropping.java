
    class Solution 
    {
        //Function to find minimum number of attempts needed in 
        //order to find the critical floor.
        static int eggDrop(int egg , int floor) 
    	{
    	    int[][] dp = new int[egg+1][floor+1];
    	    return helper(egg , floor , dp);
    	}
    	
    	static int helper(int egg , int floor , int[][] dp)
    	{
    	    if(floor == 0 || floor == 1)
    	    return floor;
    	    
    	    if(egg == 1)
    	    return floor;
    	    
    	    if(dp[egg][floor] > 0)
    	    return  dp[egg][floor];
    	    
    	    
    	    int ans = Integer.MAX_VALUE;
    	    
    	    for(int k=1 ; k<=floor ; k++)
    	    {
    	        int egg_break      =  helper(egg-1 , k-1 , dp);
    	        int egg_survives   =  helper(egg   , floor-k , dp);
    	        
    	        int temp_ans = Math.max(egg_break ,egg_survives)+1;
    	        
    	        ans = Math.min(ans , temp_ans);
    	    }
    	    
    	    return dp[egg][floor]=ans;
    	    
    	    
    	}
    	
    	
    }
