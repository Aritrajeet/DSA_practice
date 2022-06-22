//Question: https://practice.geeksforgeeks.org/problems/word-break1352/1#

//Solution:
bool solve(string a, vector<string>b){
        for (auto x:b){
                if (x == a){
                    return true;  //if right substr present in the vector
                }
            }
        for (int i=1; i<a.length(); i++){
            //cout<<a.substr(0,i)<<" "<<a.substr(i,a.length()-i)<<endl;
            string temp = a.substr(0,i);
            bool flag = false;
            for (auto x:b){
                if (x == temp){ 
                    
                    flag = true;      //if left substr present in the vector
                }
            }
            if (flag and solve(a.substr(i),b))  //if left substr present then check for right substr
                return true;
        }
        return false;     //if none present return false 
    }
    int wordBreak(string A, vector<string> &B) {
        if (solve(A,B))
            return 1;
        else return 0;
    }
