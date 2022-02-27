    vector<string> ans;
    
// We consider +1 for ( and -1 for ). So, whenever value becomes 0 and length is 2n , we have an answer.But, if value goes -ve or exceeds n we return.
    void solve(int n, int i , int val , string temp){
        if (i == 2*n){
            if (val == 0)
                ans.push_back(temp);
            return;
        }
        if (val<0 || val>n){
            return;
        }
        //add '(' to curr combo
            solve(n,i+1,val+1,temp + "(");
        
        //add ')' to curr combo
            solve(n,i+1,val-1,temp + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        string temp;
        solve(n,0,0,temp);
        return ans;
    }
