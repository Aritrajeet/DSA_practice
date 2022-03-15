//fails for testcase: /..hidden

class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        stack<string> st;
        string temp;
        int n = path.length();
        
        for (int i=0; i<n; i++){
            
            if(path[i] == '/' ){
                if (i > 1 and temp != ""){
                    st.push(temp);
                    temp = "";
                    continue;
                }
            }
            else if (path[i] == '.'){
                int count= 0 ;
                while(i<n and path[i] == '.'){
                    count++;
                    i++;
                }
                if (count == 1){
                    i--;
                    continue;
                }
                if(count == 2 ){
                    if(!st.empty())
                        st.pop();
                    else{
                        
                    }
                    i--;
                    continue;
                }
                while(count--){
                    temp += '.';
                }
                i--;
            }
            else{
                temp += path[i];
                continue;
            }
            if(!temp.empty()){
                st.push(temp);
                temp = "";
            }
        }
        
        while(!st.empty()){
            
            ans =  st.top() + ans;
            st.pop();
            ans = '/' + ans;
        }
        if (ans.empty() ) ans = '/' ;
        return ans;
    }
};
