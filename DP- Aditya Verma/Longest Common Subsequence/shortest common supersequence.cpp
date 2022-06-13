#include <iostream>
using namespace std;
// Question: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1/#

int lcs(string a, string b, int m, int n)
{
    int t[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[m][n];
}

// Function to find length of shortest common supersequence of two strings.
int shortestCommonSupersequence(string x, string y, int m, int n)
{
    int len = m + n;
    return len - lcs(x, y, m, n);
}

int main()
{
    string a, b;
    cout << "Enter first string: \n";
    cin >> a;
    cout << "Enter second string: \n";
    cin >> b;
    cout << "Length of lcs is: " << shortestCommonSupersequence(a, b, a.length(), b.length());
    return 0;
}