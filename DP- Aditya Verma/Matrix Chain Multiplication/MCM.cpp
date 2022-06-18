#include <iostream>
using namespace std;

//Recursive approach
int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);  //Left part + right part + cost of multipl
        // cout << temp << " " << ans << endl;
        ans = min(ans, temp);
    }
    return ans;
}

public: // bottom up (memoization) DP
    int t[101][101];
    int solve (int arr[], int i, int j){
        if (i >= j)
            return 0;
        if(t[i][j] != -1)
            return t[i][j];
        int ans=INT_MAX;
        for (int k=i; k<j; k++){
            int temp = solve(arr,i,k) + solve(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
           // cout<<temp<<" "<<ans<<endl;
            ans = min(ans,temp);
        }
        return t[i][j] = ans;
    }

int main()
{
    int n;
    cout << "Enter the matrix size: \n";
    cin >> n;
    int arr[n];
    cout << "Enter the matrices: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            t[i][j] = -1;
        }
    }
    cout << "The minimum no of multiplications are: " << solve(arr, 1, n - 1);
    return 0;
}
