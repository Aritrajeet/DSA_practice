//Question: https://leetcode.com/problems/majority-element-ii/


//Solution: Sort -const space
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans ;
        sort(nums.begin(),nums.end());
        int count = 1;
        for (int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                count++;
            }
            else{
                if (count > nums.size()/3){
                    ans.push_back(nums[i]);
                }
                count = 1;
            }
        }
        if (count > nums.size()/3)
            ans.push_back(nums[nums.size()-1]);
        return ans;
    }
};

//Method 2: map method - O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map <int,int> freq;
       
        for (int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for (auto x : freq){
            if (x.second > n/3)
                ans.push_back(x.first);
        }
        return ans;
    }
};
