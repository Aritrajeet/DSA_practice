// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/


class Solution {
public:
  //changing parameters : no of coins and target. Note that the k is fixed for each dice.
    int numRollsToTarget(int n, int k, int target) {
        int dp[n+1][target+1];    // dp[i][j] states that with i no of coins there are these many ways to achieve the target j.
        for (int j=0; j<target+1; j++)
            dp[0][j] = 0;
        for (int i=0; i<n+1; i++)
            dp[i][0] = 0;
        dp[0][0] = 1;     // since if coins is 0 and target is reached it is a valid scenario.
        for (int dices=1; dices<n+1; dices++){
            for (int t=1; t<target+1; t++){
                long long ans = 0;
                for (int num = 1; num <= k; num++){   // check for all face values
                    if(t<num) break;
                    ans += dp[dices-1][t - num]%1000000007;     // use the curr dice and decrement its val from the curr target.
                }
                dp[dices][t] = ans%1000000007;    // to overcome the overflow.
            }
        }
        return dp[n][target];
    }
};
