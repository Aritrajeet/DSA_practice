// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll ans = 0;
        unordered_map<int,int> m;
        ll sum = 0;
        for (int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                ans++;
            }
            if(m.find(sum) != m.end()){
                ans += m[sum];      // if the numbers result in a sum that was already present means the number between the two numbers form a 0-sum subarr. Eg: 6,-1,-3,4  here sum 6 appears twice. When it occurs 2nd time, we know -1,-2 and 4 gives a sum 0.
            }
            m[sum]++;     // This is done because whenever a new pair comes it can arrange its way in n-1 ways. Eg: {-1,-3,4},{-2,2} already exits in ans. We get another pair {0,0}. Then possible subarr are: {-1,-3,4}, {-2,2}, {0,0}, {-1,-3,4,-2,2}, {-2,2,0,0}, {-1,-3,4,-2,2,0,0}
        }
        return ans;
    }
