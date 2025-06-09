class MagicDictionary {
public:
    struct Node{
        bool isWord;
        Node* array[26];
    };

    Node* root;

    MagicDictionary() {
        root = nullptr;
    }
    
    void recInsert(Node*& node, string word){
        if(!node){
            node = new Node();
            node->isWord = false;
            for(int i=0; i<26; i++){
                node->array[i] = nullptr;
            }
        }
        if(word.empty()){
            node->isWord = true;
            return;
        }
        int idx = word[0]-'a';
        recInsert(node->array[idx], word.substr(1));
    }

    void insert(string word) {
        recInsert(root, word);
    }

    void buildDict(vector<string> dictionary) {
        for(string str : dictionary){
            insert(str);
        }
    }
    
    bool dfs(string word, Node* root, bool modified){
        if(!root)return false;
        if(word.empty()){
            return modified && root->isWord;
        }
        int idx = word[0]-'a';
        for(int i=0; i<26; i++){
            if(root->array[i]){
                if(idx == i){
                    if(dfs(word.substr(1), root->array[i], modified)){
                        return true;
                    }
                } else if(!modified){
                    if(dfs(word.substr(1), root->array[i], true)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(string searchWord) {
        return dfs(searchWord, root, false);
    }

};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */