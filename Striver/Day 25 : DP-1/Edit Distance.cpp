//Question: https://leetcode.com/problems/edit-distance/

//Solution: 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int t[m+1][n+1];
        for (int i=0; i<m+1; i++)
            t[i][0] = i;
        for (int j=0; j<n+1; j++)
            t[0][j] = j;
        for (int i=1; i<m+1; i++){
            for (int j=1; j<n+1; j++){
                if (word1[i-1] == word2[j-1]){
                    t[i][j] = t[i-1][j-1];      //no changes needed if char matches
                }
                else{
                    t[i][j] = 1 + min(min(t[i-1][j],t[i][j-1]), t[i-1][j-1]);     // try all cases: Deletion, Addition and Replace
                }
            }
        }
        return t[m][n];
    }
};
