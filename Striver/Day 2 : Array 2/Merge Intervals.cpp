//Question: https://leetcode.com/problems/merge-intervals/

//Solution:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end()); //sort acc to first element
    int first = intervals[0][0], sec = intervals[0][1];
    for(int i=0;i<intervals.size(); i++) {
        if(intervals[i][0] <= sec) {
            sec = max(sec, intervals[i][1]);      //if intervals overlap : merge them
        } else {
            ans.push_back({first, sec});      //add merged interval(from previous iteration) to the solution
            first = intervals[i][0];
            sec = intervals[i][1];
        }
    }
    ans.push_back({first, sec});      //the last one interval is left out. So, add it after the loop ends
    return ans;
}
