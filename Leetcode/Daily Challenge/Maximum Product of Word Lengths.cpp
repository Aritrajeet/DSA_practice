
//Question: https://leetcode.com/problems/maximum-product-of-word-lengths/

//Solution: Brute force - O(n4) TLE :(
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxp = 0;
        sort(words.begin(),words.end());
        for (auto x: words){
            cout<<x<<" ";
        }
        for (int i=0; i<words.size(); i++){
            for (int j=i+1; j<words.size(); j++){
                bool flag = true;
                for (int m = 0; m<words[i].length(); m++){
                    for (int n=0; n<words[j].length(); n++){
                        if (words[i][m] == words[j][n]){
                            flag = false;
                        }
                    }
                }
                if (flag){
                    int temp = words[i].length() * words[j].length();
                    maxp = max(maxp, temp);
                }
            }
        }
        return maxp;
    }
};
