int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp;
        dp.resize(size(strs), vector<vector<int> >(m + 1, vector<int>(n + 1)));
        
        // counting zeros and ones
        int ones = count(strs[0].begin(), strs[0].end(), '1');
        int zeros = strs[0].length() - ones;
        
        // initialization
        for(int i = zeros; i <= m; i++)
        {
            for(int j = ones; j <= n; j++)
            {
                dp[0][i][j] = 1;                
            }
        }
        
        for(int i = 1; i < len; i++)
        {
            ones = count(strs[i].begin(), strs[i].end(), '1');
            zeros = strs[i].length() - ones;
            
            for(int j = 0; j <= m; j++) 
            {
                for(int k = 0; k <= n; k++)  
                {
                    int notPick = dp[i - 1][j][k];
                    int pick = INT_MIN;
                    if(j - zeros >= 0 && k - ones >= 0)
                    {
                        pick = dp[i - 1][j - zeros][k - ones] + 1;               
                    }
                    dp[i][j][k] = max(pick, notPick);
                }
            }
        }
        
        return dp[len - 1][m][n];
    }
