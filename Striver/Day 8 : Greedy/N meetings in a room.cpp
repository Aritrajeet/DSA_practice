//Question: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


//Solution: Arrange all pairs in ascending orfer of finish times. Then choose the possible pairs.
int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for (int i=0; i<n; i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int pos = 0;
        for (int i=0; i<n; i++){
            if (i==0) {
                ans++;
                continue;
            }
            if (v[i].second > v[pos].first){      //here we check whether the curr meet can be possible or not by comparing the start time of this meet with the end time of previous meet
                ans++;
                pos = i;      //update the latest meet
            }
        }
        return ans;
    }
