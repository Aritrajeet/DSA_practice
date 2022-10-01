// https://leetcode.com/problems/complement-of-base-10-integer/


class Solution {
public:
    int bitwiseComplement(int n) {
        string s;
        if(n==0) return 1;
      //convert to binary
        while(n){
            s += to_string(n%2);
            n /= 2;
        }
      // flip the bits
        for (int i=0; i<s.length(); i++){
            if(s[i] == '0')
                s[i] = '1';
            else s[i] = '0';
        }
        int ans = 0;
      // get the integer back from bin representation
        for(int i=0; i<s.length(); i++){
            ans += pow(2,i)*(s[i] - '0');
        }
        return ans;
    }
};
