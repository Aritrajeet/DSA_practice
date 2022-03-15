class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (int i=0; i<s.length(); i++){            
            if ( !st.empty() and ( ( s[i] == ')' and st.top() == '(') or ( s[i] == ']' and st.top() == '[') or ( s[i] == '}' and st.top() == '{') )) {
                st.pop();   //check for latest opening bracket pair of curr closing bracket in the stack
            }
            else {
                st.push(s[i]);     //keep pushing the brackets
            }
        }
        return (st.empty());
    }
};
