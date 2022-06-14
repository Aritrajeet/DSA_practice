//Question: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/#

class Solution {
public:
    int lcs(string a, string b)
{
    int m = a.length(),n = b.length();
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

    int minDistance(string word1, string word2) {
        int len = word1.length() + word2.length();
        return len - 2*lcs(word1, word2);
    }
};
