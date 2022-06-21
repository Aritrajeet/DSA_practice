//Question: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#

//Solution: Very similar to LIS
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    if (n==1) return arr[0];
	    int ans = INT_MIN;
	    int LIS[n];
	    LIS[n-1] = arr[n-1];
	    for (int i=n-2; i>=0; i--){
	        LIS[i] = arr[i];
	        for (int j=i+1; j<n; j++){
	            if (arr[i]<arr[j])
	                LIS[i] = max(LIS[i], arr[i] + LIS[j]);
	        }
	        ans = max(ans, LIS[i]);
	    }
	    return ans;
	}  
};
