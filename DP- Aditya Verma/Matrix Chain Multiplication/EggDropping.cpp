    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.

    int t[201][201];

    int solve(int e, int f){
        if(f <= 1) return f;    //if no floor or 1 floor its the only option
        if(e == 1)      //if only one egg only safe way is to check all the floors from bottom
            return f;
        if (t[e][f] != -1)      //optimization using bottom-up DP
            return t[e][f];
        int mini = INT_MAX;
        for (int i=1; i <= f; i++){
            int eggBreak = (t[e][f] == -1) ? solve(e-1,i-1) : t[e][f];    //egg breaks so check the bottom part of building
            int noBreak = (t[e][f] == -1) ? solve(e,f-i) : t[e][f];   //egg breaks so check the top part of the building
            int temp = 1 + max(eggBreak , noBreak);     //calculate the worst case for finding out the required floor standing on ith floor
            mini = min(mini,temp);      //calculate the best case for finding out the required floor starting from any floor ( here starting means choosing the next floor based on outcome of egg drop from ith floor)
        }
        return t[e][f] = mini;
    }
    
    int eggDrop(int e, int f) 
    {
        memset(t,-1,sizeof(t));
        return solve(e,f);
    }
