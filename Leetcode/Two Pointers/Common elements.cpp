//Question: https://practice.geeksforgeeks.org/problems/common-elements1132/1

public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            set<int>s;  // to store unique values
            vector<int> ans;
            int first=0, sec=0, third=0;    //3 ptr for 3 arrays
            while(first < n1 and sec < n2 and third < n3){
                if(A[first] < B[sec]){
                    first++;
                }
                else if (B[sec] < C[third]){
                    sec++;
                }
                else if(A[first] == B[sec] and B[sec] == C[third]){
                    s.insert(A[first]);
                    first++;
                    sec++;
                    third++;
                }
                else{
                    third++;
                }
            }
            for(auto x : s){
                ans.push_back(x);
            }
            return ans;
        }
