#include <iostream>
using namespace std;

// recursive appraoch
int count = 0;
int lcs(string a, string b, int a_len, int b_len)
{
    if (a_len == 0 or b_len == 0)
    {
        return 0;
    }
    if (a[a_len - 1] == b[b_len - 1])
    {
        return 1 + lcs(a, b, a_len - 1, b_len - 1);
    }
    else
    {
        return max(lcs(a, b, a_len - 1, b_len), lcs(a, b, a_len, b_len - 1));
    }
}

// top-down approach - DP
int lcs1(string a, string b)
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
