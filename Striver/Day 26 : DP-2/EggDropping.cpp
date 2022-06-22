    int t[201][201];

    int solve(int e, int f){
        if(f <= 1) return f;
        if(e == 1)
            return f;
        if (t[e][f] != -1)
            return t[e][f];
        int mini = INT_MAX;
        for (int i=1; i <= f; i++){
            int eggBreak = (t[e][f] == -1) ? solve(e-1,i-1) : t[e][f];    //egg breaks so check the bottom part of building
            int noBreak = (t[e][f] == -1) ? solve(e,f-i) : t[e][f];   //egg breaks so check the top part of the building
            int temp = 1 + max(eggBreak , noBreak);
            mini = min(mini,temp);
        }
        return t[e][f] = mini;
    }
    
    int eggDrop(int e, int f) 
    {
        memset(t,-1,sizeof(t));
        return solve(e,f);
    }
