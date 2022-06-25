class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        
        int[][][] dp = new int[m+1][n+1][strs.length];
        
       return helper(strs , m , n , 0 , dp);
        
        
        
    }
    
    public static int helper(String[] strs , int m , int n , int idx , int[][][] dp)
    {
        if(idx == strs.length || m+n ==0)
            return 0;
        
        if(dp[m][n][idx] > 0 )
            return dp[m][n][idx];
        
        char[] arr = strs[idx].toCharArray();
        int zero = 0;
        int one = 0;
        
        
        for(char ch : arr)
        {
            if(ch=='0')
                zero++;
            else
                one++;
        }
        
        
        int consider = 0;
        
        if(zero <= m && one <= n )
            consider = 1 + helper(strs , m-zero , n-one , idx+1 , dp);
        
         int skip = helper(strs , m , n , idx+1 , dp);
        
         return dp[m][n][idx] = Math.max(consider , skip);
       
        
    }
    
    
}
