    // Naive solution is to maintain 2 loops and a sum[] array to store the number of
    // 1s present in the right of index
    
    long long int countOfSubstringWithKOnes(string s, int k){
        int n = s.length();
        int sum[n] = {0};
        int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                sum[i] += s[j] - '0';
            }
        }
        for (int i=0; i<n; i++){
            int count = 0;
            for (int j=i; j<n; j++){
                if(count>k) break;
                if (s[j] == '1') count++;
                if(count == k && sum[i]>=k){
                    ans++;
                }
            }
        }
        return ans;
    }
