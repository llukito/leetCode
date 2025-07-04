class WordDictionary {
public:
    struct Node{
        Node* children[26];
        bool isWord;
    };  
    
    Node* root;

    WordDictionary() {
        root = new Node();
        for(int i=0; i<26; i++){
            root->children[i] = nullptr;
        }
        root->isWord = false;
    }

    void addRec(Node*& root, string word){
        if(!root){
            root = new Node();
            for(int i=0; i<26; i++){
                root->children[i] = nullptr;
            }
            root->isWord = false;
        }
        if(word.empty()){
            root->isWord = true;
            return;
        }
        addRec(root->children[word[0]-'a'], word.substr(1));
    }

    void addWord(string word) {
        addRec(root, word);
    }
    
    bool searchRec(Node*& root, string word){
        if(!root)return false;
        if(word.empty())return root->isWord;
        if(word[0] == '.'){
            for(Node* nd : root->children){
                if(searchRec(nd, word.substr(1)))return true;
            }
        } else{
            if(searchRec(root->children[word[0]-'a'], word.substr(1)))return true;
        }
        return false;
    }

    bool search(string word) {
        return searchRec(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */