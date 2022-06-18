Recursive Approach :


import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
    Scanner scn = new Scanner(System.in);
    String str = scn.next();
    
    int result = paindromePartioning(str , 0 , str.length()-1 );
    System.out.println(result);

   
  }
  
  public static int paindromePartioning(String str , int i , int j)
  {
     if(i>=j || isPalindrome(str , i , j))
       return 0;

     int ans = 9999;

     for(int k = i ; k<=j-1 ; k++)
     {
       int left = paindromePartioning(str , i , k);
       int right = paindromePartioning(str , k+1 , j);

       ans = Math.min(ans , left+right+1);             
     }
     
      return ans;
 
  }

  public static boolean isPalindrome(String str , int i , int j)
  {
      boolean ans = true;
      
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












//  Memoization Approach


import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
     Scanner scn = new Scanner(System.in);
     String str = scn.next();
     
     int[][] dp = new int[str.length()][str.length()];
     
     for(int[] arr : dp)  
      Arrays.fill(arr , -1);


     int result = palindromeParitioning(str , 0 , str.length()-1 , dp);
  
     System.out.println(result);
     

  }

  public static int palindromeParitioning(String str , int i , int j , int[][] dp)
  {
     if(i>=j || isPalindrome(str , i , j))
       return dp[i][j] = 0;

     if(dp[i][j] != -1)
      return dp[i][j];

     int ans = 9999;

     for(int k=i ; k<=j-1 ; k++)
     {
         int left = palindromeParitioning(str , i , k , dp);
         int right = palindromeParitioning(str , k+1  , j ,dp);

         ans = Math.min(ans , left+right+1);
     }

    dp[i][j] = ans;

    return ans;
    
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
