class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n =boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),[] (
                const vector<int> &a, const vector<int> &b){
                return a[1] > b[1];
        });
        int ans = 0;
        int i = 0;
        while (truckSize and i< n){
            int box = boxTypes[i][0];
            while(box--){
                if(truckSize <= 0)
                    break;
                ans+= boxTypes[i][1];
                truckSize--;
            }
            i++;
        }
        return ans;
    }
};
