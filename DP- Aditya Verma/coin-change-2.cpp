#include <bits/stdc++.h>
using namespace std;

long long coinChange(int coins[], int n, int value)
{
    int dp[value + 1];
    dp[0] = 0;
    for (int i = 1; i <= value; i++)
        dp[i] = INT_MAX - 1;
    for (int i = 0; i <= value; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int temp = dp[i - coins[j]];
                dp[i] = min(1 + temp, dp[i]);
            }
        }
    }
    if (dp[value] == INT_MAX - 1)
        return -1;
    return dp[value];
}

int main()
{
    int n;
    cout << "Enter size: \n";
    cin >> n;
    int arr[n];
    cout << "Enter the denomination array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int amount;
    cout << "Enter the required amount: \n";
    cin >> amount;
    cout << "Minimum no of coins to get desired amount using denominations : \n"
         << coinChange(arr, n, amount);

    return 0;
}