#include <iostream>
using namespace std;

// top-down approach
int lcs1(string a, string b)
{
    int maxi = 0;
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
                maxi = max(maxi, t[i][j]);
            }
            else
            {
                t[i][j] = 0;
            }
        }
    }
    return maxi;
}

int main()
{
    string a, b;
    cout << "Enter first string: \n";
    cin >> a;
    cout << "Enter second string: \n";
    cin >> b;
    cout << "Length of lcs is: " << lcs1(a, b);
    return 0;
}