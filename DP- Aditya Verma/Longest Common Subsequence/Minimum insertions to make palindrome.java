import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception
  {
    Scanner scn = new Scanner(System.in);
    String s1 = scn.next();
    String s2 = "";

    for(int i=s1.length()-1 ; i>=0 ; i--)
     s2 += s1.charAt(i);
   
    int[][] dp = new int[s1.length()+1][s2.length()+1];

    for(int i=1 ; i<dp.length ; i++)
    {
      for(int j=1 ; j<dp[0].length ;j++)
      {
         if(s1.charAt(i-1) == s2.charAt(j-1) )
           dp[i][j] = 1 + dp[i-1][j-1];

         else
           dp[i][j] = Math.max(dp[i-1][j] , dp[i][j-1]);
      }
    }


   System.out.println("No Of Insertion to be done : " + (s1.length()-dp[dp.length-1][dp[0].length-1]) );
 

  }
}
  
    
