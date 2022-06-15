class Solution {
    public int longestStrChain(String[] words) {
        
    Arrays.sort(words, new Comparator<String>() {

      public int compare(final String s1, final String s2) {
        return s1.length() - s2.length();
      }
    });
        
        
    HashMap<String , Integer> hm = new HashMap<>();
    hm.put(words[0] , 1);    
    int result = 1;
        
    for(String val : words)
    {
        int ans = 0;
        
        for(int i=0 ; i<val.length() ; i++)
        {
            String temp = val.substring(0,i) + val.substring(i+1);
   
            if(hm.containsKey(temp))
             ans = Math.max(ans , hm.get(temp));
        }
        
        hm.put(val , ans+1);
        
        result = Math.max(result , ans+1);
    
        
    }
        
        
        return result;
        
    }
}
