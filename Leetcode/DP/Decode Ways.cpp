// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int dp[s.length()]; // dp[i] stores the no of encoding possible till ith ele of string
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        for (int i=1; i<s.length(); i++){
            if(s[i] == '0' and s[i-1] == '0'){    // no chance of valid ans
                // cout<<"1";
                return 0;
            }
            else if(s[i] != '0' and s[i-1] == '0'){
                // cout<<"2";
                dp[i] = dp[i-1];    // you can only add curr element since '06' is not same as '6'
            }
            else if(s[i] == '0' and s[i-1] != '0'){   // you cant add curr element so check if you can add last 2 element together
                // cout<<"3";
                if(s[i-1] == '1' or s[i-1] == '2'){
                    dp[i] = (i>1 ? dp[i-2] : 1);
                }
                else {
                    return 0;
                }
            }
            else{
                // cout<<"4";
                if(stoi(s.substr(i-1,2)) <= 26){    //check for last 2 ele. last ele will anyways be added.
                    dp[i] = dp[i-1] + (i>1 ? dp[i-2] : 1);
                }
                else dp[i] = dp[i-1];
            }
        }
        return dp[s.length()-1];
    }
};
