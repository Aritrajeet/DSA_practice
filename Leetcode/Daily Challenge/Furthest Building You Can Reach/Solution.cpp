class Solution {
public:     //idea is to assign all ladders first by putting it into the min heap then when size is full keep poping the min element and use bricks until they too get finished
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;      //min heap to keep track of the minimum diff till now
        
        int n = heights.size();
        int brickSum = 0;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
          
            if(diff <= 0) continue;     //no need of brick or ladder
            
            pq.push(diff);
            if(pq.size() > ladders) {     //ladders finished
                brickSum += pq.top();
                pq.pop();
            }   
            if(brickSum > bricks) return i - 1;     //bricks finished
        }
        return n-1;    
    }
};
