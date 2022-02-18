    string decodeString(string s) {
        stack <char> st;
        for (int i=0; i<s.length(); i++){
            if (s[i] != ']'){
                st.push(s[i]);      //keep pushing all elements in the stack except ']' 
            }
            else{
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    char c = st.top();
                    st.pop();
                    temp = c + temp;   //to retain the original order of string since stack sends reverse string.
                }
                st.pop();   //remove ']'
                string freq;    //freq is a string containing frequency of string inside []
                while(!st.empty() && (st.top() >= '0' && st.top() <= '9')){
                    freq = st.top() + freq; //same logic to reverse
                    st.pop();
                }
               
                int n = stoi(freq);     //convert to int. n has actual freq
                string str;
                while(n--){
                    str += temp;
                }
                for (int i=0; i< str.length(); i++){
                    st.push(str[i]);
                }
            }
        }
        //Now we have the required string in the stack : just need to return it.
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
