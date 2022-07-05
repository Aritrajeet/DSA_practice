//Question: https://leetcode.com/problems/implement-trie-prefix-tree/

//Solution:
struct Node{
    Node * link[26];
    bool flag = false;
    
    bool containsKey(char c){
        return (link[c-'a'] != NULL);
    }
    
    void put(char c, Node *node){
        link[c-'a'] = node;
    }
    
    Node * get(char c){
        return link[c-'a'];
    }
    
    void end(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {  
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (int i=0; i< word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }  
            node = node->get(word[i]);
        }
        node->end();
    }
    
    bool search(string word) {
        Node *node = root;
        for (int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }  
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }  
            node = node->get(prefix[i]);
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
