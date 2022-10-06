// https://leetcode.com/problems/time-based-key-value-store/


class TimeMap {
public:

    map<string,vector<pair<int,string>>> m;
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
      // Linear search
        // string ans;
        // int time = 0;
        // for (auto x: m[key]){
        //     if(x.first <= timestamp){
        //         if(x.first > time){
        //             time = x.first;
        //             ans = x.second;
        //         }
        //     }   
        // }
        
      // Binary search
        int left = 0; int right = m[key].size();
        string ans = "";
        while(left<right){
            int mid = left + (right - left)/2;
            if(m[key][mid].first <= timestamp){
                ans = m[key][mid].second;
                left = mid+1;     // even you get a valid timestamp try for the bigger time stamps
            }
            else{
                right = mid;
            }
        }
        return ans;
    }
};
