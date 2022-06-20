//Question: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

//Solution: class Solution{
public:
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
    
    int matrixMultiplication(int N, int arr[])
    {
        
        for (int i=0; i<101; i++){
            for (int j=0; j<101; j++){
                t[i][j] = -1;
            }
        }
        return solve(arr,1,N-1);
    }
