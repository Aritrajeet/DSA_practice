//Question: 

//Solution: Using map
  int *findTwoElement(int *arr, int n) {
      int *ans = new int[2];
      unordered_map<int,int> mp;
      
      for(int i=0; i<n; i++)
      {
          mp[arr[i]]++;
      }
      
      
      for(int i=0; i<n; i++)
      {
          if(mp[arr[i]] == 2)     //repeating element
          {
              ans[0] = arr[i];
              break;
          }
      }
      
      for(int i=1; i<=n; i++)
      {
          if(mp.count(i) == false)      //missing element
          {
              ans[1] = i;
              break;
          }
      }
      return ans;
   }
