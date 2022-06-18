Recursive Approach :

import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
     Scanner scn = new Scanner(System.in); 
     int egg = scn.nextInt();
     int floor = scn.nextInt();

     int result = eggDropping(egg , floor);
     System.out.println(result);

  }

  public static int eggDropping(int egg , int floor)
  {
     if(egg == 1)
      return floor;

     if(floor == 0 || floor == 1)
       return floor;

     int ans = 9999;

     for(int i=1 ; i<=floor ; i++)
     {
       int temp_ans = Math.max(eggDropping(egg-1 , k-1 ) , eggDropping(egg , floor-k )) + 1;
       ans = Math.min(ans , temp_ans);
     }

     return ans;

  }
}







Memoization Approach :


import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {   
    Scanner scn = new Scanner(System.in);
    int egg = scn.nextInt();
    int floor = scn.nextInt();
  
    int[][] dp = new int[egg+1][floor+1];

    for(int[] arr : dp)
     Arrays.fill(arr , -1);

    int result = eggDropping(egg , floor , dp);
    System.out.println(result);
  }

  public static int eggDropping(int egg , int floor , int[][] dp)
  {
     if(egg == 1)
      return floor;

     if(floor == 0 || floor == 1)
      return floor;

     if(dp[egg][floor] != -1)
      return dp[egg][floor];

     int ans = 9999;

     for(int k=1 ; k<=floor ; k++)
     {
        int temp_ans = Math.max(eggDropping(egg-1 , k-1 , dp) , eggDropping(egg , floor-k , dp)) + 1;
        ans = Math.min(ans , temp_ans);
     }
    
     return dp[egg][floor] = ans;

  }

}
