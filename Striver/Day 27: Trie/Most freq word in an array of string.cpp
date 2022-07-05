//Question: https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/0/?track=DSASP-Trie&batchId=154#


//Solution:
struct Node{
    Node * links[26];
    int countWords = 0;
    
     // check if reference trie present
    bool containsKey(char c)
    {
        if (links[c - 'a'] != NULL)
            return true;
        return false;
    }

    // creating reference trie
    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    // get the next node for traversal
    Node *get(char c)
    {
        return links[c - 'a'];
    }

    // set the flag true wherever a string ends
    void setEnd()
    {
        countWords++;
    }

    // checks if curr trie is the end of string
    int words()
    {
        return countWords;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    int countW(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;

            node = node->get(word[i]);
        }
        return (node->words());
    }
};


class Solution
{
    public:
    Trie t;
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        map<string,int> m;
        for (int i=0; i<n ; i++){
            t.insert(arr[i]);   
        }
        int maxi = INT_MIN;
        string ans;
        for (int i=0; i<n; i++){
            if(m.find(arr[i]) == m.end()){
                int temp = t.countW(arr[i]);
                if (temp >= maxi){
                    ans = arr[i];
                    maxi = temp;
                }
                m[arr[i]] = temp;
            }
        }
        return ans;
    }
};
