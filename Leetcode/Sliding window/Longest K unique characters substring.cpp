// Was asked at SIXT interview. Print longest substring with k unique chars.

//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int max_len = -1;
        int i=0,j=0;
        map<char,int> m;
        while(j<s.length()){
            m[s[j]]++;      //calculation
            int un = m.size();
            if(un < k){     //window not yet achieved
                j++;
            }
            else if (un == k){      //window achieved - k unique characters
                max_len = max(max_len,j-i+1);     //answer
                j++;
            }
            else {
                while(m.size() > k){      //more than k unique characters
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                        m.erase(s[i]);      //remove the char which are not present in the window
                    i++;      //slide the window
                } 
                j++;      //dont forget this -> curr j index value is already calculated.
            }
        }
        return max_len;
    }
};
