#include <iostream>
using namespace std;

int solve(string &s, int i, int j, bool isTrue, int ***t)
{

    if (t[i][j][isTrue] != -1) // isTrue is a bool variable to denote true or false condition for the current call
    {
        return t[i][j][isTrue];
    }
    if (i == j) // either T or F
    {
        t[i][j][true] = (s[i] == 'T'); // return true if the required bool val is present
        t[i][j][false] = (s[i] == 'F');
        return t[i][j][isTrue];
    }
    int ans = 0;
    for (int k = i + 1; k < j; k += 2) // k += 2 because k accounts for operators which are present in odd indices
    {
        char op = s[k];                                                                          // curr operator
        int lt = (t[i][k - 1][true] == -1) ? solve(s, i, k - 1, true, t) : t[i][k - 1][true];    // left expression gives true
        int lf = (t[i][k - 1][false] == -1) ? solve(s, i, k - 1, false, t) : t[i][k - 1][false]; // left expression gives false
        int rt = (t[k + 1][j][true] == -1) ? solve(s, k + 1, j, true, t) : t[k + 1][j][true];    // right expression gives true
        int rf = (t[k + 1][j][false] == -1) ? solve(s, k + 1, j, false, t) : t[k + 1][j][false]; // right expression gives false

        if (op == '|')
        {
            if (isTrue)
            {
                ans += (lt * rt + lt * rf + lf * rt); // condition for OR operator to give true
            }
            else
            {
                ans += (lf * rf); // condition for OR operator to give false
            }
        }
        else if (op == '&')
        {
            if (isTrue)
            {
                ans += (rt * lt);
            }
            else
            {
                ans += (lt * rf + lf * rt + lf * rf);
            }
        }

        else if (op == '^')
        {
            if (isTrue)
            {
                ans += (lt * rf + lf * rt);
            }
            else
            {
                ans += (lt * rt + lf * rf);
            }
        }
    }
    ans = ans % 1003;      // to avoid overflow
    t[i][j][isTrue] = ans; // 3D dp used to optimize
    return ans;
}

int countWays(int N, string S)
{
    // 3D dp initialization
    int ***t = new int **[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        t[i] = new int *[N + 1];
        for (int j = 0; j < N + 1; j++)
        {
            t[i][j] = new int[2];
            t[i][j][0] = -1;
            t[i][j][1] = -1;
        }
    }
    return solve(S, 0, N - 1, true, t);
}

int main()
{
    string s;
    cout << "Enter the boolean expression: \n";
    cin >> s;
    cout << countWays(s.length(), s);
    return 0;
}