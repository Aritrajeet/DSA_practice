class Solution {      //We solve the question in reverse direction. i.e. we start from target if even divide by 2 and if odd add 1. Stop when we reach start value.
public:
    int brokenCalc(int k, int target) {
        int ans=0;
        while (target > k){     
            if (target%2 == 0){
                target /= 2;
                ans++;
            }
            else{
                target++;
                ans++;
            }
        }
        
        return ans + k - target;      //if target becomes more than k we have no other option then to subtract target
    } 
};
