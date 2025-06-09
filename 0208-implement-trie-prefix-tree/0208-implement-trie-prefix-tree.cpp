class Trie {
public:
    struct Node{
        bool isWord;
        Node* array[26];
    };

    Node* root;

    Trie() {
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
    
    Node* dfs(Node* root, string word){
        if(!root || word.empty())return root;
        return dfs(root->array[word[0]-'a'], word.substr(1));
    }

    bool search(string word) {
        Node* r = dfs(root, word);
        return r && r->isWord;
    }
    
    bool startsWith(string prefix) {
        return dfs(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */