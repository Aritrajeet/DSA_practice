class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=0;
        int sum=0;
        int n = costs.size();
        for (int i=0; i<n; i++){
            sum += costs[i][0];     //sum of all costs of A
        }
        ans = sum;
        vector<int> v;
        for (int i=0; i<n; i++){
            v.push_back(costs[i][1] - costs[i][0]);     //vector of differences
        }
        sort(v.begin(),v.end());
        for (int i=0; i<n/2; i++){      //add the least difference i.e. these people are from city B
            ans += v[i];
        }
        return ans;
    }
};
