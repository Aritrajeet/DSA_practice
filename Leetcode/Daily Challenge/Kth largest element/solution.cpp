//method 1 : O(nlogn)   
int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        return nums[k-1];
    }

//method 2 : O(nlogk) - Using priority queue
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> pq;
        for (int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        for (int i=k; i<nums.size(); i++){
            if (nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
