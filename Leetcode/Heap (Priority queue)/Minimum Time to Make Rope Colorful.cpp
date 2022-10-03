// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

// NOTE- There is a better greedy solution than this. See inside Greedy folder.
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        priority_queue<int,vector<int>, greater<int>> pq;     // min heap
        pq.push(neededTime[0]);     // insert the first balloon
        int ans = 0;
        for (int i=1; i<colors.length(); i++){
            if(colors[i] == colors[i-1]){
                pq.push(neededTime[i]);     // insert the time of all same balloons
            }
            else {
                while(pq.size() > 1){     // once you see a different balloon you know now you need to remove the previous balloons and keep only the max one
                    ans += pq.top();
                    pq.pop();
                }
                pq.pop();     // after you have removed all loons remove the last one too for further computations
                pq.push(neededTime[i]);     // push the new loon
            }
        }
        while(pq.size() > 1){     // repeat for the last set of loons
                    ans += pq.top();
                    pq.pop();
                }
        return ans;
    }
};
