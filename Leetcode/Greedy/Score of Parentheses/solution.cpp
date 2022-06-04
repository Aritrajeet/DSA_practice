class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int n = s.length();
        int i=0;
        map<char,bool> m;     //to keep track of visited char
        for (int c='a';c<'z'; c++){
            m[c] = false;       //not visited
        }
        int p=0;
        while(i != n){
        
            int end = n-1;
            int temp = -1;
            while(i!=temp){ 
                if(m[s[i]] == false){
                    
                    if (end <= temp ){      //duplicate doesnt exist in right of end of curr group
                        i++;
                        end = n-1;
                        continue;
                    }
                    if(s[i] == s[end]){     //duplicate found or group complete
                        temp = end;
                        if (i==temp){     //group complete
                            break;
                        }
                        end = n-1;      //reset end pointer for next iteration
                        m[s[i]] = true;
                        i++;
                        
                    }
                    else{
                        end--;      //traverse from back to find a duplicate
                    }
                }
                
                else{
                    i++;
                    end = n-1;
                }   
            
            }
            ans.push_back(temp-p+1);
            i = temp+1;
            p = i;
        }
        return ans;
    }
};
