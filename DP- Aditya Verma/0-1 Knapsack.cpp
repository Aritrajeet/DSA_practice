#include <iostream>
using namespace std;

//We will solve the classic 0-1 Knapsack problem using all 3 methods : 1) Recursive  2) Memoization  3) Top-down

// recursive 0-1 knapsack
int knapsack(int wt[], int val[], int W, int n)
{
    if (W == 0 or n == 0)
        return 0;
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else
    {
        return knapsack(wt, val, W, n - 1);
    }
}

// memoization
int t[11][11]; // max length of arr (n) = 10 and max weight = 10 . We create table of parameters that change with the recursive calls.

int knapsack_1(int wt[], int val[], int W, int n)
{
    if (W == 0 or n == 0)
        return 0;
    if (t[W - 1][n - 1] != -1)
    {
        return t[W - 1][n - 1];
    }
    if (wt[n - 1] <= W)
    {
        return t[W - 1][n - 1] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else
    {
        return t[W - 1][n - 1] = knapsack(wt, val, W, n - 1);
    }
}

// top-down approach
int knapsack_2(int wt[], int val[], int W, int n)
{
    int t1[n + 1][W + 1];
    // for top-down dp, base condition becomes initialization
    for (int i = 0; i < n + 1; i++)
    {
        t1[i][0] = 0; // first col = 0 since W = 0
    }
    for (int i = 0; i < W + 1; i++)
    {
        t1[0][i] = 0; // first row = 0 since n = 0
    }

    // Replace recursion calls with dp array blocks. Also replace n with i and W with j
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t1[i][j] = max(val[i - 1] + t1[i - 1][j - wt[i - 1]], t1[i - 1][j]);
            }
            else
            {
                t1[i][j] = t1[i - 1][j];
            }
        }
    }

    return t1[n][W]; // the last cell of the table has the answer.
}

int main()
{
    int n;
    cout << "Enter size: \n";
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item-" << i + 1 << endl;
        cin >> wt[i];
        cout << "Enter value of item-" << i + 1 << endl;
        cin >> val[i];
    }
    int W;
    cout << "Enter bag capacity: ";
    cin >> W;

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            t[i][j] = -1;
        }
    }

    cout << "Maximum val you can get is : " << knapsack_2(wt, val, W, n) << endl;
    return 0;
}
