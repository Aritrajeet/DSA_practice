//Question: https://leetcode.com/problems/trapping-rain-water/

//Solution: curr_rain_height = min(left_maxHeight , right_maxHeight) - currHeight
class Solution {
public:
    int trap(vector<int>& height) {
        int curr_rain = 0;
        vector<int>left_max;
        int l_max = INT_MIN;
        vector<int>right_max;
        int r_max = INT_MIN;
        for (int i=0; i<height.size(); i++){      // prefix : left max
            l_max = max(l_max,height[i]);
            left_max.push_back(l_max);
        }
        for (int i=height.size()-1; i>=0; i--){     //suffix : right max
            r_max = max(r_max,height[i]);
            right_max.push_back(r_max);
        }
        reverse(right_max.begin(),right_max.end());
        int ans=0;
        for (int i=0; i<height.size(); i++){
            curr_rain = min(left_max[i],right_max[i]) - height[i];
            ans += curr_rain;
        }
        return ans;
    }
};
