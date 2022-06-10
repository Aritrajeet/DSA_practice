//Question : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#


//Solution:
    int findPlatform(int arr[], int dep[], int n)
    {
     	int i=1;    // arrival ptr
    	int j=0;    // departure ptr
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int maxi=1;     //max platforms needed
    	int p = 1;    //curr platforms
    	while(i<n and j<n)
    	{
    	    if (arr[i]<=dep[j])     // if a train arrives when platform busy
    	    {
    	        p++;      //allocate another platform
    	        i++;      
    	    }
    	    else //if (arr[i]<dep[j])
    	    {
    	        p--;      
    	        j++;
    	    }
    	    maxi=max(maxi,p);
    	}
    	return maxi;
    	
    }
