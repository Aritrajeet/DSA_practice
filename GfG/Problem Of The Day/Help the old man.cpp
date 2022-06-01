//Question : https://practice.geeksforgeeks.org/problems/help-the-old-man3848/1#

//Solution: Tower of Hanoi Problem
class Solution{
public:
    vector<pair<int, int>> ans;
    void hanoi(int n, int box1, int box2, int box3) {
        if(n == 0) {
            return;
        }
        hanoi(n-1, box1, box3, box2);
        ans.push_back({box1, box3});
        hanoi(n-1, box2, box1, box3);
    }

    vector<int> shiftPile(int N, int n){
        // code here
        hanoi(N, 1, 2, 3);
        return {ans[n-1].first, ans[n-1].second};
    }
};
