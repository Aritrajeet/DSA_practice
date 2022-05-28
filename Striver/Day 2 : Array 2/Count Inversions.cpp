//Question: 

//Solution: We use the idea of merge sort....we make some change in the merge function to count the number of inversions
#include <bits/stdc++.h> 
long long int ans = 0;
void merge(long long *arr,long long  left,long long mid,long long right){
    long long n1 = mid - left + 1;
    long long n2 = right - mid;
    long long l[n1],r[n2];      //left subarr and right subarr
    for (long long i=0; i<n1; i++){
        l[i] = arr[left+i];
    }
    for (long long i=0; i<n2; i++){
        r[i] = arr[mid+i+1];
    }
    long long i=0,j=0,k=left;
    while(i<n1 and j<n2){     //merge two subarr into 1
        if (l[i] <= r[j])
            arr[k++] = l[i++];     
        else{
            arr[k++] = r[j++];
            ans += (n1 - i);    //if an element from left subarr is greater than one element on right subarr all elements to its right will also be greater than that element.
        }
    }
    while(i<n1){
        arr[k++] = l[i++];
    }
    while(j<n2){
        arr[k++] = r[j++];
    }
}
void mergeSort(long long *arr,long long left, long long right){     //normal merge sort function
    if (left >= right) return;
    long long mid = left + (right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
long long getInversions(long long *arr, int n){
    mergeSort(arr,0,n-1); //left=0 , right = n-1 
    return ans;
}
