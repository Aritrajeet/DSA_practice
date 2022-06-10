//Question: 


//Solution: Sort on basis of val/wt ratio
double fractionalKnapsack(int W, Item arr[], int n)
   {

     vector<pair<double,int>> ques(n);
     for(int i = 0;i<n;i++)
     {
         double per = (arr[i].value*1.0)/(arr[i].weight*1.0);
         ques[i] = {per,i};
     }
 
     sort(ques.rbegin(),ques.rend();

     double sum = 0;
     for(int i = 0; i<n;i++ ){
         if(arr[ques[i].second].weight<= W){
            W -=   arr[ques[i].second].weight;      //Full fill
            sum += arr[ques[i].second].value;
         }
         else{
             sum += W*ques[i].first;      //fractional fill
             break;
         }
     }
     return sum;
   }
        
};
