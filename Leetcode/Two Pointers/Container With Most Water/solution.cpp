class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right = height.size()-1;
        int h1=0,h2=0;
        int area=0;
        while(left < right){
            int len = right - left;
            int mini = min(height[left],height[right]);     //Water will fill according to the least height wall.
            area = max(area, len*mini);     //taking max of all areas
            if (height[left] < height[right]){  //move ptrs to get the max height walls.
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};
