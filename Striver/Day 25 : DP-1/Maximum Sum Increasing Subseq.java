class Solution
{
	public int maxSumIS(int arr[], int n)  
	{  
	    //code here.
	    
	    int[] dp = new int[arr.length];
	    
	    
	    int ans = Integer.MIN_VALUE;
	    
	    
	    for(int i=0 ; i<dp.length ;i++)
	    {
	        int temp = 0;
	        
	        for(int j=0 ; j<i ; j++)
	        {
	             if(arr[j] < arr[i])
	             temp = Math.max(temp , dp[j]);
	        }
	        
	        dp[i] = temp+arr[i];
	        ans = Math.max(ans , dp[i]);
	        
	    }
	    

	    return ans;
	    
	    
	}  
}
