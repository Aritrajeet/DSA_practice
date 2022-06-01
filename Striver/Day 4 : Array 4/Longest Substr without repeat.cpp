//Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

//Solution:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r = n-1;
        
        unordered_set<char> s;      //set to keep track of elements so that we can find duplicate
        
        int len = 0;

        for(int r=0 ;r<n ;r++)
        {
            if(s.find(s[r]) == s.end())     //if curr ele is not present in set it means that the curr substr is unique
            {
                s.insert(s[r]);
                len = max(len,r-l+1);     //increase curr count of substr
                
            }
            else
            {
                while(l!=r && s[l]!=s[r])     //if duplicate found remove from left until the duplicate char is removed
                    visited.erase(s[l++]);
                
                visited.erase(s[l++]);     //Removing and adding the same element and increase the left pointer
                visited.insert(s[r]);
                
                len = max(len,r-l+1);    
            }
        }
        
        return len;
    }
};
