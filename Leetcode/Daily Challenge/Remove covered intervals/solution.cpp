/*Firstly we sort the array according to first index.
  3 cases possible : 
  Case 1:   -----
              ------
              
  Case 2 :  -----
                  -----
                  
  Case 3 :  -------
              ---
              
  we remove case 3.
                  
*/
int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int count = 1;
        int left = arr[0][0];
        int right = arr[0][1];
        for (int i=1; i<n; i++){
            if (arr[i][0] > left && arr[i][1] > right){
                left = arr[i][0];
                count++;
            }
            right = max(right,arr[i][1]);       //for choosing right for case 1 and 2
        }
        return count;
    }
