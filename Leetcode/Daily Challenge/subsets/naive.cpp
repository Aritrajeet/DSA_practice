//This implementation is on strings. A similar logic can be designed for arrays.
//for every element we either include it or exclude it.
void subsetRec(string s, vector<string> &ans, int i, string temp){
    if (i>=s.length()){
        ans.push_back(temp);    //All leaf nodes are subsets of the string
        return;
    }
    subsetRec(s,ans,i+1,temp);  //exclude s[i]
    temp += s[i];
    subsetRec(s,ans,i+1,temp);   //include s[i]
}

vector<string> subsets(string s){
    string temp="";
    vector<string> ans;
    subsetRec(s,ans,0,temp);
    return ans;
}
