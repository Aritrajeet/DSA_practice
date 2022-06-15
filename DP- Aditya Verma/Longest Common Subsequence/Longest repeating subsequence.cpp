#include <iostream>
using namespace std;

// Question: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

int LongestRepeatingSubsequence(string str)
{
    int n = str.length();
    int t[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str[i - 1] == str[j - 1] and i != j) // here we form 2 groups of lcs. So if same characters are present in different index, they are part of LCS
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][n];
}

int main()
{
    string a;
    cout << "Enter the string: \n";
    cin >> a;
    cout << LongestRepeatingSubsequence(a);
    return 0;
}