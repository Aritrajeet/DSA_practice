    vector<vector<string>> ans;
    
// function to check whether current Queen is attacked by another or not.
    bool isSafe(vector<string> temp,int r, int c){
        //check for Q in column
        for (int i=r-1; i>=0; i--){
            if(temp[i][c] == 'Q')
                return false;
        }
        //no need to check for Q in row since we search from next row onwards
        
        //check for Q in left to right diagonal 
        for (int i=r-1,j=c-1; i>=0 && j>=0; i--, j--){
            if (temp[i][j] == 'Q')
                return false;
        }
        //check for Q in right to left diagonal 
        for (int i=r-1, j=c+1; i>=0 && j<temp.size(); i--, j++){
            if (temp[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void solve(vector<string> &temp, int r){
        
        if(r == temp.size()){
            ans.push_back(temp);
                return ;
        }
        for (int j=0; j<temp.size(); j++){    // For each column we place the Queen in current row and traverse the row to check if its the correct position
            if (isSafe(temp,r,j)){
                temp[r][j] = 'Q';     //Consider that Q is placed here
                solve(temp,r+1);      //solve next row
                temp[r][j] = '.';     //Consider that Q is not placed here (backtrack)
            }
        }     
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
      //create empty board
        for (int i=0;i<n; i++){
            string s;
            for (int j=0; j<n; j++)
                s +='.';
            temp.push_back(s);
        }
        solve(temp,0);
        return ans;
    }
