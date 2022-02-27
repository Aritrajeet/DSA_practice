class Solution {
    public List<String> generateParenthesis(int n) {
        
        result = new ArrayList<>();
        helper(2*n,"",0,0,n);                   
        return result;
        
        
    }
    
    static List<String> result;
    
    public static void helper(int n, String ans, int count1, int count2 , int elements)    // count1 and count2 will keep track of no of ( and ) .
    {
        if(n==0)
        {
            result.add(ans);
            return ;
        }
        
        if(count1 < elements)                                  // this will prevent having more than n "(".
         helper(n-1,ans+"(",count1+1,count2,elements);
        
        if(count2 < count1)
          helper(n-1,ans+")",count1,count2+1,elements);         // this will prevent from having more than "(" because that is invalid.
        
    }  
}
