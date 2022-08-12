// https://leetcode.com/problems/sliding-window-maximum/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0,j=0;
        deque<int> q;     //we need to use deque since we will be accessing elements from both the ends
        while(j<nums.size()){
            int w_size = j-i+1;
            if(!q.empty()){     // Any number smaller than curr ele is of no use because it can't be a max. So, we remove it from the queue and add it to the deque
                while(!q.empty() and nums[j] > q.back())
                    q.pop_back();
                q.push_back(nums[j++]);
            }
            else {
                q.push_back(nums[j++]);     //if empty queue simply add 
            }
            if(w_size == k){      //window achieved
                ans.push_back(q.front());     //answer will always be in the front of the queue. WHY? Because all the smaller elements before j were removed on the go (from back of queue) and the max survived. All smaller elements after the curr j were added from back
                if(nums[i] == q.front()){ 
                    q.pop_front();
                }
                i++;      //move to next window
            }
        }
        return ans;
    }
