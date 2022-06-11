#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> v;
    void subset_sum(int arr[], int n, int target)
    {
        bool t[n + 1][target + 1];
        // when n = 0
        for (int j = 0; j < target + 1; j++)
            t[0][j] = false;
        // when target = 0
        for (int i = 0; i < n + 1; i++)
            t[i][0] = true;
        Solution::v.push_back(1); // first col of last row is 1
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] or t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
                if (i == n and j <= target / 2)
                {
                    Solution::v.push_back(t[i][j]); // Store the last row till mid into a vector
                }
            }
        }
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        subset_sum(arr, n, sum);
        int mini = INT_MAX;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i])
            {
                mini = min(mini, sum - 2 * i); // calculate the min diff since (s2-s1) ->min implies ((sum - s1)-s1)->min
            }
        }
        return mini;
    }
};

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
    Solution s;
    cout << "Minimum diff is: " << s.minDifference(arr, n);
    return 0;
}
