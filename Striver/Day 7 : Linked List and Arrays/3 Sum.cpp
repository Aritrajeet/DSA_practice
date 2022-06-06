//Question: https://leetcode.com/problems/3sum/

//Solution: 1) Naive : O(n3)

// 2) Better : insert in a map and check for existence of the desired sum O(n2*logn)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map <int,int> m;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        set<vector<int>>s;
        vector<vector<int>> ans;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]]--;
            for (int j=i+1; j<nums.size(); j++){
                m[nums[j]]--;
                if (m.find(0 - nums[i] - nums[j]) != m.end() and m[0 - nums[i] - nums[j]] != 0){
                    vector<int>temp = {nums[i],nums[j],0 - nums[i] - nums[j]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        for (auto x: s){
            ans.push_back(x);
        }
        return ans;
    }
};

// Optimized: 2 ptr .Sort it. Selct one number a (iterate) then b + c = -a using 2 ptr. Dont perform operations for same high and low.
