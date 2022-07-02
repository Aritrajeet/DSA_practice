class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        int mod = 1000000007;
        sort(hCuts.begin(),hCuts.end());
        sort(vCuts.begin(), vCuts.end());
        int diff1 = hCuts[0];
        int diff2 = vCuts[0];
        for (int i=1; i<hCuts.size(); i++){
            diff1 = max(diff1,hCuts[i] - hCuts[i-1]);
        }
        diff1 = max(diff1,h - hCuts[hCuts.size()-1]);
        diff1 %= mod;
        
        for (int i=1; i<vCuts.size(); i++){
            diff2 = max(diff2,vCuts[i] - vCuts[i-1]);
        }
        diff2 = max(diff2,w - vCuts[vCuts.size()-1]);
        diff2 %= mod;
        long long int ans = (1LL*diff1*diff2) % mod;
        return ans;
    }
};
