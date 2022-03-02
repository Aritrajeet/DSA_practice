//2 ptr for 2 strings   
bool isSubsequence(string s, string t) {
        int s_idx = 0, t_idx = 0;
        int count = 0;
        while(s_idx < s.length() && t_idx < t.length()){
            if(s[s_idx] == t[t_idx]){
                count++;
                s_idx++;
                t_idx++;
            }
            else t_idx++;
        }
        return (count==s.length() ? true : false);
    }
