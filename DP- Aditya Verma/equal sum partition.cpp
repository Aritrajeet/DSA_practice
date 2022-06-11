// Question: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int target)
{
    int t[n + 1][target + 1];
    for (int j = 0; j < target + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] or t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][target];
}

bool equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return false;
    if (subsetSum(arr, n, sum / 2))
        return true;
    return false;
}

int main()
{
    int n;
    cout << "Enter no of elements: \n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (equalSumPartition(arr, n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}