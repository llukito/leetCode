class Solution {
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        string name;
        bool toDelete = false;
        TrieNode(string n = "") : name(n) {}
    };
    
    TrieNode* root = new TrieNode();
    unordered_map<string, vector<TrieNode*>> dupMap;

    void insert(vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder))
                node->children[folder] = new TrieNode(folder);
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";
        vector<string> serializedParts;
        for (auto& [name, child] : node->children) {
            serializedParts.push_back(name + "(" + serialize(child) + ")");
        }
        sort(serializedParts.begin(), serializedParts.end());
        string serial = join(serializedParts, "");
        dupMap[serial].push_back(node);
        return serial;
    }

    string join(const vector<string>& parts, const string& sep) {
        string res;
        for (const string& part : parts) res += part + sep;
        return res;
    }

    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (child->toDelete) continue;
            path.push_back(name);
            res.push_back(path);
            collect(child, path, res);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) insert(path);

        serialize(root);
        
        for (auto& [s, nodes] : dupMap) {
            if (nodes.size() > 1) {
                for (TrieNode* node : nodes) {
                    node->toDelete = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> currPath;
        collect(root, currPath, res);
        return res;
    }
};
