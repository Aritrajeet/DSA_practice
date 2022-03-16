class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        
        
      Stack<Integer> st = new Stack<>();
      st.push(pushed[0]);
        
      int i = 1;
      int j = 0;
    
        
        while( i != pushed.length || j!= popped.length)                  // if stack top element equals to popped jth index then pop it from stack otherwise push it in stack.
        {
            if(st.size() == 0)
            {
                st.push(pushed[i]);
                i++;
             }
           else if(  st.peek() != popped[j])
            {
                if(i == pushed.length)
                    break;
               
                st.push(pushed[i]);
                i++;
               
            }
            else if(st.peek() == popped[j])
            {
                st.pop();
                j++;
            }
            
            
        }
        
                                        // if u come out of while loop and stack is empty that means the following operations are possible return true else return false.
        if(st.size()>0)
            return false;
        else
            return true;
        
        
        
    }
}
