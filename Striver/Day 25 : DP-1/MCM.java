class Solution{
    static int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        int[][] dp = new int[arr.length][arr.length];
        
        for(int[] arrr : dp)
          Arrays.fill(arrr , -1);
        
        return mcm(arr , 1 , arr.length-1 , dp);
        
    }
    
    public static int mcm(int[] arr , int i , int j , int[][] dp)
    {
        
        if(i>=j)
        return dp[i][j] = 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int ans = Integer.MAX_VALUE;
        
        for(int k = i ; k<=j-1 ; k++)
        {
            
            int left = mcm(arr , i , k ,dp);
            int right = mcm(arr , k+1 , j , dp);
            
            ans = Math.min(ans , left+right+arr[i-1]*arr[k]*arr[j]);
            
            
        }
    
        return dp[i][j] = ans;
    }
    
}

