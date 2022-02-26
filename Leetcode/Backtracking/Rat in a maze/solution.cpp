    vector<string> ans;
    
    void solve(vector<vector<int>> &m, int n, int i, int j, string temp){
        //check for invalid cell
        if (j<0 || i<0 || j>= n || i>=n || m[i][j] == 0){
            return;     //index going out of boundary OR invalid cell
        }
      
        //destination reached
        if (i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        m[i][j] = 0;        //mark as visited
        
        //go left
        solve(m,n,i,j-1,temp +'L');
        //go up
        solve(m,n,i-1,j,temp +'U');
        //go right
        solve(m,n,i,j+1,temp +'R');
        //go down
        solve(m,n,i+1,j,temp +'D');
        
        m[i][j] = 1;        //mark as unvisited (backtrack)
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string temp;
        solve(m, n, 0,0 , temp);
        return ans;
    }
