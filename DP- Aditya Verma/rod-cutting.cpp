#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    int t[n + 1][n + 1]; // t[price][length]
    int length[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        length[i] = i + 1;
    }
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int j = 0; j < n + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][n];
}

int main()
{
    int n;
    cout << "Enter size: \n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Maximum profit is : " << cutRod(arr, n);
    return 0;
}
