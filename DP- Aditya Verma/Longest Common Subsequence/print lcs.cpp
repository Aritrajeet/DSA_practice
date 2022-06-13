#include <iostream>
using namespace std;

string lcs1(string a, string b)
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
    string ans;
    int i = a.length(), j = b.length();
    while (i > 0 and j > 0)
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
                i--;
            }
            else
                j--;
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
    cout << "Longest common subsequence string is: " << lcs1(a, b);
    return 0;
}