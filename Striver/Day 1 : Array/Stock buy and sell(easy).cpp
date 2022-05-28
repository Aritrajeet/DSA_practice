//Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//Solution:
class Solution {
public:     //Though this is linear but there is a better approach using DP
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int mini = INT_MAX;
        int profit;
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < mini){
                mini = prices[i];       //keep track of the minimum element on the left of curr element
            }
            profit = prices[i] - mini;
            if (profit > max_profit){
                max_profit = profit;      //try to sell at every point and check the profit
            }
        }
        return max_profit;
    }
};
