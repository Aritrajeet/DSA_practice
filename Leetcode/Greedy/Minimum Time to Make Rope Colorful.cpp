// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/


class Solution {
public:
        int minCost(string s, vector<int>& cost) {
        int ans = cost[0], max_cost = cost[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                ans -= max_cost;      // exclude the max cost since we are not going to remove it
                max_cost = 0;
            }
            ans += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        return ans - max_cost;
    }
};
