// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int ans  = 0;
        map<char,int> m;
        while(j<s.length()){
            m[s[j]]++;      // calculation
            if(m[s[j]] > 1){      // repeated char in the window
                while(m[s[j]] > 1){     //decrease the window from front until all chars in the window are unique
                    m[s[i++]]--;
                }
                j++;
            }
            else if(m[s[j]] == 1){
                ans = max(ans,j-i+1);     //calculate the ans
                j++;
            }
        }
        return ans;
    }
};
