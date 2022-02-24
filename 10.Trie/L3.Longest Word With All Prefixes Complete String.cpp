struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 
class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); //insert if not exist
            }
            node = node->get(word[i]); //move to refrence trie
        }
        node->setEnd(); //set the flag true,set insert
    }
    
    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        bool flag = true; 
        for(int i = 0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]); 
                flag = flag & node->isEnd(); //flag has to be true
            }
            else {
                return false; 
            } 
        }
        return flag; 
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();  
    for(auto word : a) obj->insert(word); 
    string longest = ""; //initial longest null
    for(auto word: a) { //iterate across everyone
        if(obj->checkIfAllPrefixExists(word)) { //if all the prefix do exist
            if(word.size() > longest.size()) {
                longest = word; 
            }
            else if(word.size() == longest.size() && word < longest) {
                longest = word; 
            }
        }
    }
    if(longest == "") return "None"; //if didnt find anyone return none
    return longest; 
}