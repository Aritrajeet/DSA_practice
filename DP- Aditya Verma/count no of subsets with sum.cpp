#include <iostream>
using namespace std;

int count_subset_sum(int arr[], int n, int target)
{
    int t[n + 1][target + 1];
    // when n = 0
    for (int j = 0; j < target + 1; j++)
        t[0][j] = 0;
    // when target = 0
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][target];
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
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    if (count_subset_sum(arr, n, target) == 0)
    {
        cout << "Sum not present";
    }
    else
        cout << "No of subsets with given sum: " << count_subset_sum(arr, n, target);
    return 0;
}
