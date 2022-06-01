//Question: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#


//Solution: Prefix sum
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> m;     //map to store the prefix sum as key with the index as value
        int count=0;
        int sum = 0;
        for (int i=0; i<n; i++){
            sum += A[i];      //Prefix sum
            if (sum == 0){
                count = i+1;      //This means that the subarr starts from the beggining itself
            }
            else if (m.find(sum) != m.end()){
                count = max(count, i-m[sum]);     //If you find the prefix sum in the map means that you can arrive at that sum again after i - that sum's position. That also means that the elements between i and m[sum] sum up to 0
            }
            else{
                m[sum] = i;
            }
        }
        return count;
    }
};
