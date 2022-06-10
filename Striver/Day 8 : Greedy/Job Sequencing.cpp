//Question: 


//Solution: (explaination : Striver) Insights: Finish job just before deadline and start from max profit job and allocate it to last date i.e. deadline
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>> p;
        for (int i=0; i<n; i++){
            p.push_back({arr[i].profit, arr[i].dead});
        }
        sort(p.rbegin(),p.rend());

        
        int max_dead = -1;
        for (auto x : p){
            max_dead = max(max_dead , x.second);
        }
        vector <int> job (max_dead);
        for (auto x : job){
            x = 0;
        }
        int count = 0;
        for (auto x : p){
            int idx = x.second - 1;
            while(idx >= 0){
                if (job[idx] != 0){
                    idx--;
                }
                else {
                    count++;
                    job[idx] = x.first;
                    break;
                }
            }
        }
        int sum = 0;
        for (auto x : job){
            sum += x;
        }
        return {count,sum};
    } 
