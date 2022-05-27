//Question: 

//Solution : Method 1 : O(n) extra space O(m+n) time
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=0,p2=0;
        vector <int> temp;
        while(p1 < m and p2 < n){
            if (nums2[p2] < nums1[p1]){
                temp.push_back(nums2[p2++]);
            }
            else temp.push_back(nums1[p1++]);
        }
        while(p1<m){
            temp.push_back(nums1[p1++]);
        }
        while(p2<n){
            temp.push_back(nums2[p2++]);
        }
        nums1 = temp;
    }
};

//Method 2: O(1) extra space O(n*m)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=0;
        if (nums2.empty()) return;
        while(p1<m){
            if (nums1[p1] <= nums2[0]){
                p1++;
                continue;
            }
            else{
                swap(nums1[p1],nums2[0]);
                sort(nums2.begin(),nums2.end());  //can be done in linear too
            }
        }
        for (int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
    }
};
