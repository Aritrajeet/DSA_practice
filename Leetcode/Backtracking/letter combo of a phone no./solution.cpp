    vector<string> ans;
    
    void solve(string digits,string letters[], int idx,string temp){
        if(idx == digits.length()){
            ans.push_back(temp);    //one permutation is ready
            return;
        }
        int n = (digits[idx]-'0');
        
        for (int i=0; i< letters[n].length(); i++){           
            temp.push_back(letters[n][i]);    //consider current letter in the permutation
            solve(digits,letters,idx+1,temp);
            temp.pop_back();    //backtrack
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0);
        string letters[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;  
        string temp;
        solve(digits,letters,0,temp);
        if (ans[0] == "")
            ans.pop_back();   
        return ans;
    }
