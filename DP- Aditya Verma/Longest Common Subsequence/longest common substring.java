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
    int result = 0;

    
    for(int i=1 ; i<dp.length ; i++)
    {
      for(int j=1 ; j<dp[0].length ; j++)
      {
         if(s1.charAt(i-1) == s2.charAt(j-1))
           dp[i][j] = 1 + dp[i-1][j-1];
           
         else
           dp[i][j] = 0;

         result = Math.max(result , dp[i][j]);

      } 
    }
   
    System.out.println(result);
  }
}
