class Solution{
    static int palindromicPartition(String str)
    {
        int[][] dp = new int[str.length()][str.length()];
        return helper(str , 0 , str.length()-1 , dp);
    }
    
    public static int helper(String str, int i , int j , int[][] dp)
    {
        if(i>=j || isPalindrome(str , i , j) )
        return 0;
        
        if(dp[i][j] > 0)
        return dp[i][j];
        
        int ans = Integer.MAX_VALUE;
        
        for(int k=i ; k<=j-1 ; k++)
        {
            int temp_ans  =  helper(str , i , k , dp ) + helper(str , k+1 , j , dp) ;
            ans = Math.min(temp_ans +1 , ans);
        }
        
        return dp[i][j] = ans;
    }
    
    public static boolean isPalindrome(String str , int i , int j)
    {
        while(i<j)
        {
            if(str.charAt(i) == str.charAt(j))
            {
                i++;
                j--;
            }
            
            else
            return false;
        }
        
        return true;
    }
    
    
}
