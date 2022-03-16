class Solution {
    public String minRemoveToMakeValid(String s) {
        
       Stack<Integer> st = new Stack<>();
        
       for(int i=0 ; i<s.length() ; i++)
       {
           char ch = s.charAt(i);
           
           if(ch == '(')
               st.push(i);
           
           else if(st.size() >0 && ch == ')' &&  s.charAt(st.peek()) == '(')
               st.pop();
           
           else if(ch == ')')
               st.push(i);
           
           else
               continue;
              
       }                                               //   storing the string index which is in unordered form.
        
        
        String ans = "";
        
        while(st.size() > 0)
        {
            int temp = st.pop();
            ans = s.substring(0,temp) +  s.substring(temp+1);              // Removing all the unordered parenthessis from String.
            s = ans;
            
        }
        
        
        return s;
        
    }
}
