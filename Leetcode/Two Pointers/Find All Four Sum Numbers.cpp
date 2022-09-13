// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

// time complexity: O(n3)
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        set<vector<int>> s;   //to maintain unique quadraples
        sort(arr.begin(),arr.end());    // we want to apply 2 ptr
        for (int i=0; i<arr.size()-3; i++){
            for (int j = i+1; j<arr.size()-2; j++){
                int temp_sum = arr[i] + arr[j];     // fix 2 numbers
                int left = j+1;
                int right = arr.size()-1;
                while(left < right){      // using 2 ptrs find the rest 2 numbers
                    if(arr[left] + arr[right] + temp_sum == k){
                        s.insert({arr[i],arr[j],arr[left],arr[right]});
                        left++;     // whenever a quadraple is found, there is still a posibility of finding more quadraples. So, move both the ptrs ahead.
                        right--;
                    }
                    else if (arr[left] + arr[right] + temp_sum < k){
                        left++;
                    }
                    else right--;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto x : s){
            ans.push_back(x);   // since the set already contains vector no need to create a temp vector
        }
        return ans;
    }
