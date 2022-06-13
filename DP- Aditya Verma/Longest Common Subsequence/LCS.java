// Recursive Approach


import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
    Scanner scn = new Scanner(System.in);
    String s1 = scn.next();
    String s2 = scn.next();

    int ans = LCS(s1 , s2 , s1.length() , s2.length());
    System.out.println(ans);
  }


   public static int LCS(String s1 , String s2 , int m , int n )
   {
     if(m==0 || n==0)
      return 0;

     if(s1.charAt(m-1) == s2.charAt(n-1))
      return 1 + LCS(s1,s2,m-1,n-1);

     else
      return Math.max(LCS(s1,s2,m-1,n) , LCS(s1,s2,m,n-1));
   }


}


// Top Down Approach

import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
    Scanner scn = new Scanner(System.in);
    String s1 = scn.next();
    String s2 = scn.next();

    int[][] dp = new int[s1.length()+1][s2.length()+1];
     
     for(int i=1 ; i<dp.length ; i++)
     {
       for(int j=1 ; j<dp[0].length ; j++)
       {
           if(s1.charAt(i-1) == s2.charAt(j-1))
            dp[i][j] = 1 + dp[i-1][j-1];

           else
            dp[i][j] = Math.max(dp[i-1][j] , dp[i][j-1]);
       }
     }


     for(int[] val : dp)
     {
       for(int vall : val)
        System.out.print(vall + " ");

      System.out.println();
     }


  }
}
