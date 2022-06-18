Recursive Approach :

import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception
  {
    Scanner scn = new Scanner(System.in);
    String a = scn.next();
    String b = scn.next();
    
    boolean ans = false;

    if(a.length() != b.length())
     ans = false;

    else
     ans = scrambledString(a , b);

     System.out.println(ans);
  }


   public static boolean scrambledString(String a , String b)
   {
      if(a.equals(b) == true)
       return true;

      if(a.length() <= 1)
       return false;

      
       boolean ans = false;

       for(int i=1 ; i<=a.length()-1 ; i++)  
       {
            boolean cond1 =   (scrambledString(a.substring(0 , i) , b.substring(a.length()-i))
                                                         &&
                              (scrambledString(a.substring(i) , b.substring(0 , a.length()-i))) ) ;


            boolean cond2 =   (scrambledString(a.substring(0 , i) , b.substring(0 , i))
                                                       &&
                              (scrambledString(a.substring(i) , b.substring(i))) );


           if(cond1 || cond2 )
           {
             ans = true;
             break;
           }
       }

       return ans;


   }

}



Memoized Approach :

import java.io.*;
import java.util.*;

class program
{
  public static void main(String[] args) throws Exception
  {
    Scanner scn = new Scanner(System.in);
    String a = scn.next();
    String b = scn.next();
    
    boolean ans = false;

    if(a.length() != b.length())
     ans = false;

    else
     ans = scrambledString(a , b);

     System.out.println(ans);
  }


    static HashMap<String,Boolean> hm = new HashMap<>();     
 
   public static boolean scrambledString(String a , String b)
   {
      if(a.equals(b) == true)
       return true;

      if(a.length() <= 1)
       return false;


      String key = ""+a+"_"+b;
    
      if(hm.containsKey(key) == true)
        return hm.get(key);

      
       boolean ans = false;

       for(int i=1 ; i<=a.length()-1 ; i++)  
       {
            boolean cond1 =   (scrambledString(a.substring(0 , i) , b.substring(a.length()-i))
                                                         &&
                              (scrambledString(a.substring(i) , b.substring(0 , a.length()-i))) ) ;


            boolean cond2 =   (scrambledString(a.substring(0 , i) , b.substring(0 , i))
                                                       &&
                              (scrambledString(a.substring(i) , b.substring(i))) );


           if(cond1 || cond2 )
           {
             ans = true;
             break;
           }
       }

       hm.put(key , ans);

       return ans;


   }

}
