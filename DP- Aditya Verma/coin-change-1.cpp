#include <bits/stdc++.h>
using namespace std;

int coinChange(int arr[], int n, int amount)
{
    int t[n + 1][amount + 1];

    for (int j = 0; j < amount + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][amount];
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
    cout << "No of combinations to get desired amount using denominations : \n"
         << coinChange(arr, n, amount);

    return 0;
}