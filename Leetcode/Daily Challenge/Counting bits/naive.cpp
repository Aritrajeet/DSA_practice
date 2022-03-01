    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<= n; i++){
            int count = 0;
            int temp = i;
            while(temp){
                count += temp % 2;
                temp /= 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
