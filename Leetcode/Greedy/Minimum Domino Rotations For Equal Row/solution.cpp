class Solution {      //Idea is to count occurence of numbers at both sides, whichever is more rotate the other ends.
public:     
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map <int,int> top_m;
        map <int,int>bottom_m;
        
        for (int i=0; i<tops.size(); i++){
                top_m[tops[i]]++;           // count occurences of numbers
            }
        for (int i=0; i<bottoms.size(); i++){
                bottom_m[bottoms[i]]++;
            }
        int temp1 = INT_MIN;        //max count of number
        int temp2 = INT_MIN;
        int big1=0;         //number that is repeated max
        int big2=0;
        
        for (auto x : top_m){
               if(x.second>temp1){
                   temp1 = x.second;
                   big1 = x.first;
               }
        }
        for (auto x : bottom_m){
            if(x.second>temp2){
               temp2 = x.second;
                big2 = x.first;
            }
        }
        if (temp1>temp2){
            int count=0;
            for (int i=0;i<tops.size(); i++){
                if (tops[i] == big1)
                    continue;
                else{
                    count++;
                    if (bottoms[i] != big1)
                        return -1;
                }
            }
            return count;
        }
        else{
            int count=0;
            for (int i=0;i<bottoms.size(); i++){
                if (bottoms[i] == big2)
                    continue;
                else{
                    count++;
                    if (tops[i] != big2)
                        return -1;
                }
            }
            return count;
        }  
    }
};
