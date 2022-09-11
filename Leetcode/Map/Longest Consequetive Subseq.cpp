    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int maxi = 0;
      unordered_set<int>s;
      for(int i=0; i<N; i++){
          s.insert(arr[i]);
      }
      int end = 0;
      for (int i=0; i<N; i++){
          if(s.find(arr[i]-1) == s.end()){
              end = arr[i];
              while(s.find(end) != s.end()){
                  end++;
              }
              maxi = max(maxi, end - arr[i]);
          }
      }
      return maxi;
    }
