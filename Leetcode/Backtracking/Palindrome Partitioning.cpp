// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> ans;
    // function to check palindrome
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
    void solve(string s, int idx, vector<string> &temp){
        // base case : when all characters read
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }
        
        //body
        for(int i = idx; i<s.length(); i++){
            if(isPalindrome(s,idx,i)){      // check if the string (from idx next to prev palindrome to the curr idx) is palindrome or not
                temp.push_back(s.substr(idx, i- idx + 1));      // if palindrome add it to the temp string
                solve(s,i+1,temp);    // move on to the next index
                temp.pop_back();
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,temp);
        return ans;
    }
};
