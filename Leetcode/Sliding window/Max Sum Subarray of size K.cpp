    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long sum=0;
        long maxi = INT_MIN;
        if(n < k){  //corner case
            return 0;
        }
        int i=0, j=0;
        while(j<n){
            sum += arr[j];    //calculation
            if(j-i+1 == k){   //window achieved
                maxi = max(maxi,sum);   //answer calculation
                sum -= arr[i];  //preparation for next window
                i++;  //slide to next window
                j++;
            }
            else{
                j++;    //window not yet achieved
            }
        }
        return maxi;
    }
