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
      for(int j=1 ; j<dp[0].length ;j++)
      {
         if(s1.charAt(i-1) == s2.charAt(j-1))
           dp[i][j] = 1 + dp[i-1][j-1];

         else
           dp[i][j] = Math.max(dp[i-1][j] , dp[i][j-1]);
      }
    }


    String ans = "";

    int i = dp.length-1;
    int j = dp[0].length-1;

    while(i>0 && j>0)
    {
       if(s1.charAt(i-1) == s2.charAt(j-1))
       {
         ans = s1.charAt(i-1) + ans;
         i--;
         j--;
       }
       else
       {
         if(dp[i-1][j] > dp[i][j-1])
         {
           ans = s1.charAt(i-1) + ans;
           i--;
           
         }
        else
        {
          ans = s2.charAt(j-1) + ans;  
          j--;
        }
       }
    }

    while( i!= 0)
    {
       ans = s1.charAt(i-1) + ans;
       i--;
    }

    while( j!= 0)
    {
       ans = s2.charAt(j-1) + ans;
       j--; 
    }

  

  System.out.println(ans);

 }
}
