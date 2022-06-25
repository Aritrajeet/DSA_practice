class Sol
{   public static int wordBreak(String A, ArrayList<String> B )
    {
       HashSet<String> hs = new HashSet<>();
       HashMap<String,Integer> hm = new HashMap<>();
       
       for(String val : B)
        hs.add(val);

       return helper(A , B , hs , hm);

    }
    
     public static int helper(String A , ArrayList<String> B ,HashSet<String> hs , HashMap<String,Integer> hm )
    {
        if(A.length() == 0)
         return 1;
        
        if(hm.containsKey(A))
          return hm.get(A);
        
        int ans = 0;
         
         for(int i=0 ; i<A.length() ; i++)
         {
            String pre = A.substring(0,i+1);
            if(hs.contains(pre) == true){
             ans = helper(A.substring(i+1) , B , hs , hm);
             
             if(ans == 1)
             break;
             
            }
         }
           
    
      
          hm.put(A,ans);
      
        return ans;
      
    }
    
   
}
