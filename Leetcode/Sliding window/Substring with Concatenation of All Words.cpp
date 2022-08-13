// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), total = words.size(), len = words[0].size(); 
        vector<int> answer;

        unordered_map<string, int> freq;
        for(auto w: words){     //add all words in the map
            freq[w]++;
        }        

        for(int i = 0; i < n - total * len + 1; i++){     //i goes from 0 to the first index of last window
            int j = i;
            unordered_map<string, int> stats = freq;
            int covered = 0;      //count how many words matched
            while(covered < total && j + len - 1 < n) {
                string word = s.substr(j, len);
                if(stats.find(word) != stats.end() && --stats[word] >= 0) {       // check if the word is present in the map. If yes decrement its count.
                    covered++;
                    j += len;
                }else break;
            }
            if(covered == total) answer.push_back(i);     //all words present in the window: add to the answer.
        }

        return answer;
    }
};
