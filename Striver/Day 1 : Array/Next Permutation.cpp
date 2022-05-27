
//Question: https://leetcode.com/problems/next-permutation/

//Solution:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();  
        
        bool flag = false;
        for (int i= n-1; i> 0 ; i--){
            
            if (nums[i-1]>=nums[i]){    //dont do anything till smaller element is found from the end
                continue;
            }
            else{
                flag = true;
                int temp1 = i-1;        //first index to operate
                int mini1 = nums[temp1];
                int temp2;              //second index to operate
                int mini2 = INT_MAX;
                for (int j=temp1+1 ;j<n ; j++){     //find the next smallest number from the index of match to the end of arr i.e. [i,n]
                    if (nums[j]>mini1){
                        if(mini2>nums[j])
                        { 
                            mini2 = nums[j];
                            temp2 = j;
                        }
                    }
                }
                swap(nums[temp1],nums[temp2]);      //swap with next largest number
                sort(nums.begin()+temp1+1,nums.end());    //sort the rest of the array
                break;
            }
        }
        if (!flag){
            sort(nums.begin(),nums.end());      //for decreasing array next permutation is sorted array
        }
    }
};
