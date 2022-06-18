Recursive Approach :

import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();

    int[] arr = new int[n];

    for(int i=0 ; i<arr.length ; i++)
      arr[i] = scn.nextInt();

   
    int result = MCM(arr , 1 , arr.length-1);
     
    System.out.println(result); 
    	
  }

  static int MCM(int[] arr , int i , int j)
  {
     if(i>=j)
      return 0;
      
      int ans = 999999;

      for(int k=i ; k<=j-1 ; k++)
      {
         int left  =  MCM(arr , i , k);
         int right =  MCM(arr , k+1 , j);
     
         ans = Math.min(ans , left+right+ (arr[i-1]*arr[k]*arr[j]) );
      }
     
     return ans;
  }

}









// Memoization Approach


import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
     Scanner scn = new Scanner(System.in); 
     int n = scn.nextInt();
     
     int[] arr = new int[n];
     for(int i=0 ; i<arr.length ; i++)
       arr[i] = scn.nextInt();

    int[][] dp = new int[arr.length][arr.length];
    
    for(int[] ar : dp)
     Arrays.fill(ar , -1);  
   
    int result = MCM(arr , 1 , arr.length-1 , dp);
    System.out.println(result);  
    
  }

  public static int MCM(int[] arr , int i , int j , int[][] dp)
  {
       if(i>=j)
        return 0;

       if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 9999;

       for(int k=i ; k<=j-1 ; k++)
       {
          int left  = MCM(arr , i , k , dp);
          int right = MCM(arr , k+1 , j , dp);

          ans = Math.min(ans , (arr[i-1]*arr[k]*arr[j]) + left + right );
       }
       
       dp[i][j] = ans;

       return ans;
  }

}
