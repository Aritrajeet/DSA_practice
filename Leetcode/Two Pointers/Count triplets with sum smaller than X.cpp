// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long ans = 0;
	    sort(arr,arr+n);
	    for (int i=0; i<n-1; i++){
	        long long left = i+1,right = n-1;
	        while(left < right){
	            if(arr[i] + arr[left] + arr[right] < sum){
	                ans += (right - left);      // By observation, if arr[left] , arr[right] forms a triplet with arr[i] means all numbers between left and right will also form a triplet with arr[left]
	                left++;   // It is possible that even by increasing the left it forms a triplet
	            }
	            else right--;     // If sum is greater or equal to x, there is no option then to decrease right
	        }
	    }
	    return ans;
	}
