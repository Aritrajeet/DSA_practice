#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int t[501][501];
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int solve(string s, int i, int j)
{

    if (t[i][j] != -1)
        return t[i][j];
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s, i, j))
        return 0;

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        // optimization :We check the sub problems in our dp matrix too.
        if (t[i][k] != -1)
            left = t[i][k];
        else
            t[i][k] = left = solve(s, i, k);

        if (t[k + 1][j] != -1)
            right = t[k + 1][j];
        else
            t[k + 1][j] = right = solve(s, k + 1, j);

        int temp = left + right + 1;
        ans = min(ans, temp);
    }
    return t[i][j] = ans;
}

int palindromicPartition(string str)
{
    for (int i = 0; i < 501; i++)
        for (int j = 0; j < 501; j++)
            t[i][j] = -1;
    return solve(str, 0, str.length() - 1);
}

int main()
{
    string s;
    cout << "Enter the string: \n";
    cin >> s;
    cout << "Minimum no of palindromic partiotions is: \n"
         << palindromicPartition(s);
    return 0;
}