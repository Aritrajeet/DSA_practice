class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        for (int i=0; i<n; i++){
            s += 'a';     //initialize with all 'a'
            k--;
        }
        for (int i=n-1; i>=0; i--){
            if ((k+1) / 26){      //if feasible assign 'z'
                s[i] = 'z';
                k -= 25;
                continue;
            } 
            int temp = (k+1) % 26;      //assign any alphabet acc to the amount left.
            s[i] = char('a' + temp - 1);
            k -= (temp - 1);
            if (k == 0){
                break;
            }
        }
        return s;
    }
};
