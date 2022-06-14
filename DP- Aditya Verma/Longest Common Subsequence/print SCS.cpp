#include <iostream>
using namespace std;

string printShortestCommonSupersequence(string a, string b, int m, int n)
{
    string ans;
    int t[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        t[i][0] = 0;
    for (int j = 0; j < n + 1; j++)
        t[0][j] = 0;
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
    int i = m, j = n;
    while (t[i][j])
    {
        if (a[i - 1] == b[j - 1])
        {
            ans = a[i - 1] + ans;
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                ans = a[i - 1] + ans;
                i--;
            }
            else
            {
                ans = b[j - 1] + ans;
                j--;
            }
        }
    }
    return ans;
}

int main()
{
    string a, b;
    cout << "Enter first string: \n";
    cin >> a;
    cout << "Enter second string: \n";
    cin >> b;
    cout << "SCS is: " << printShortestCommonSupersequence(a, b, a.length(), b.length());
    return 0;
}