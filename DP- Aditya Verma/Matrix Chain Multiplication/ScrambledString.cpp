
unordered_map <string,bool> mp;

bool solve(string S1, string S2)
{
    
    // Strings of non-equal length
    if (S1.length() != S2.length()) {
        return false;
    }
 
    int n = S1.length();
 
    // Empty strings are scramble strings
    if (n == 0) {
        return true;
    }
 
    // Equal strings are scramble strings
    if (S1 == S2) {
        return true;
    }
    
    string key = S1 + " " + S2;     //This will serve as the key for all substring pairs
    if (mp.find(key) != mp.end())
        return mp[key];
        
 
    // Check for the condition of anagram : for optimization
    string copy_S1 = S1, copy_S2 = S2;
 
    sort(copy_S1.begin(), copy_S1.end());
    sort(copy_S2.begin(), copy_S2.end());
 
    if (copy_S1 != copy_S2) {
        return false;
    }
 
    for (int i = 1; i < n; i++) {
 
        //case 1 : swaped and scrambled
        if (solve(S1.substr(0, i), S2.substr(0, i))
            && solve(S1.substr(i, n - i),
                          S2.substr(i, n - i))) {
            return mp[key] = true;
        }
 
        //case 2 : not swaped and scrambled
        if (solve(S1.substr(0, i),
                       S2.substr(n - i, i))
            && solve(S1.substr(i, n - i),
                          S2.substr(0, n - i))) {
            return mp[key] = true;
        }
    }
 
    // If none of the above
    // conditions are satisfied
    return mp[key] = false;
}

int Solution::isScramble(const string a, const string b) {
    return solve(a,b);
}
