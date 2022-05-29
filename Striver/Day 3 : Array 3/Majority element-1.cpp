//Question: https://leetcode.com/problems/majority-element/

//Solution: Mehode 1: Sort and middle : O(nlogn)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//method 2 : map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans ;
        map <int,int> freq;
       
        for (int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for (auto x : freq){
            if (x.second > n/2){
                return x.first;
            }
        }
        return -1;
    }
};
