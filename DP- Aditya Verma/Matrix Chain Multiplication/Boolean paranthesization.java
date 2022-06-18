Recursive Approach :

import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception
  {
    Scanner scn = new Scanner(System.in);
    String expr = scn.next();

    int result = trueParenthesis(expr , 0 , expr.length()-1 , true);
    System.out.println(result);
       
  }

   public static int trueParenthesis(String expr , int i  , int j , boolean isTrue)
   {
       if(i > j)
        return 0;

        if(i==j)
        {
            if(isTrue == true)
              return expr.charAt(i) == 'T' ? 1 : 0 ;
            else
              return expr.charAt(i) == 'F' ? 1 : 0 ;
        }

        int ans = 0;

        for(int k = i+1 ; k<=j-1 ; k=k+2)
        {
           int lt = trueParenthesis(expr , i , k-1 , true);
           int lf = trueParenthesis(expr , i , k-1 , false);
           int rt = trueParenthesis(expr , k+1 , j , true);
           int rf = trueParenthesis(expr , k+1 , j , false);

           if(expr.charAt(k) == '&')
           {
              if(isTrue == true)
               ans += lt*rt;
              else
               ans += lt*rf+lf*rt+lf*rf;

           }

           else if(expr.charAt(k) == '|')
           {
              if(isTrue == true)
               ans += lt*rf+lf*rt+lt*rt;
              else
               ans += lf*rf;

           }

           else
           {
              if(isTrue == true)
               ans += lt*rf+lf*rt;
              else
               ans += lt*rt+lf*rf;
           }


        }

        return ans;

   }

}







// Memoization Approach:


import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception 
  {
    Scanner scn = new Scanner(System.in);
    String expr = scn.next();
    HashMap<String,Integer> hm = new HashMap<>();

    int result = trueParenthesis(expr , 0 , expr.length()-1 , true , hm);
    System.out.println(result);

  }

  public static int trueParenthesis(String expr , int i , int j , boolean isTrue , HashMap<String,Integer> hm)
  {
     if(i>j)
      return 0;

     if(i==j)
     {
        if(isTrue == true)
        return expr.charAt(i) == 'T' ? 1 : 0;
        else
        return expr.charAt(i) == 'F' ? 1 : 0;
     }

     String key = "" + i + j + isTrue;
      
     if(hm.containsKey(key))
      return hm.get(key);

     int ans = 0;      
     for(int k=i+1 ; k<=j-1 ; k=k+2)
     {
       int lt = trueParenthesis(expr , i , k-1 , true , hm);
       int lf = trueParenthesis(expr , i , k-1 , false , hm);
       int rt = trueParenthesis(expr , k+1 , j , true , hm);
       int rf = trueParenthesis(expr , k+1 , j , false , hm);


       if(expr.charAt(k) == '&')
       {
            if(isTrue == true)
               ans += lt*rt;
            else
               ans += lt*rf+lf*rt+lf*rf;

       }

       else if(expr.charAt(k) == '|')
       {
            if(isTrue == true)
              ans += lt*rf+lf*rt+lt*rt;
            else
              ans += lf*rf;

       }

       else
       {
           if(isTrue == true)
              ans += lt*rf+lf*rt;
            else
              ans += lt*rt+lf*rf; 
       }

     }

     hm.put(key , ans);
     return ans;

  }


}

