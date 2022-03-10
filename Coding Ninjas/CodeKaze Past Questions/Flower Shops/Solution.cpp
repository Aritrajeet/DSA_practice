#include<bits/stdc++.h>
using namespace std;

int price(int arr[] , int n){
    int count = 1;
    sort(arr,arr+n);
    int temp=0;
    for (int i=0; i<n; i++){
        if (arr[i] >= arr[temp] && arr[i] <= arr[temp]+4){
            continue;
        }
        else{
            count++;
            temp = i;
        }
    }
    return count;
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin>>arr[i];
    cout<< price(arr,n);
    return 0;
}
