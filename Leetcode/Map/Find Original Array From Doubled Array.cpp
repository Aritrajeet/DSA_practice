// https://leetcode.com/problems/find-original-array-from-doubled-array/

    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> m;
        vector<int> ans;
        if(changed.size()%2){
            return ans;
        }
        sort(changed.begin(),changed.end());    // all the double elements will move backwards. So, for a particular n we have already made calculations for n/2
        for (int i=0; i<changed.size(); i++){
            if(changed[i]%2 == 0 and m[changed[i]/2] > 0){  // if number is even and its half is present in the map with some count>1 then it forms a valid pair
                ans.push_back(changed[i]/2);
                m[changed[i]/2]--;    // remove the element whose pair is already made. there is a possibily of multiple element so set can't be used. Eg: [0,0,0,0]
            }
            else m[changed[i]]++;
        }
        cout<<ans.size();
        if(ans.size() == changed.size()/2){     // for the arr to be valid double it should be half the size of the original array.
            return ans;   
        }
        ans.clear();
        return ans;
    }
