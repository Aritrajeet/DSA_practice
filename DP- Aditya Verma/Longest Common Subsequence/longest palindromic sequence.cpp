#include <iostream>
#include <bits/stdc++.h>
//#include<string.h>
using namespace std;

int lcs(string a, string b)
{
    int t[a.length() + 1][b.length() + 1];
    for (int i = 0; i < a.length() + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j < b.length() + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i < a.length() + 1; i++)
    {
        for (int j = 1; j < b.length() + 1; j++)
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
    return t[a.length()][b.length()];
}

int longestPalinSubseq(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    return lcs(a, b);
}

int main()
{
    string a;
    cout << "Enter the string: \n";
    cin >> a;
    cout << longestPalinSubseq(a);
    return 0;
}