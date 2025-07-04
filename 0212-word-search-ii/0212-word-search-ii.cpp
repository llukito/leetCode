class Solution {
public:
    struct Node {
        Node* children[26];
        bool isWord;
        Node() : isWord(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    Node* root = nullptr;

    void addRec(Node*& node, const string& w, int i) {
        if (!node) node = new Node();
        if (i == w.size()) {
            node->isWord = true;
            return;
        }
        addRec(node->children[w[i] - 'a'], w, i + 1);
    }
    void addWord(const string& w) { addRec(root, w, 0); }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = nullptr;
        for (auto& w : words) addWord(w);

        int R = board.size(), C = board[0].size();
        unordered_set<string> found;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                Node* nd = root->children[board[r][c] - 'a'];
                if (nd) {
                    fill(found, string(1, board[r][c]), board, {}, r, c, nd);
                }
            }
        }
        return { found.begin(), found.end() };
    }

private:
    void fill(unordered_set<string>& found,
              string path,
              vector<vector<char>>& B,
              unordered_set<int> visited,
              int r, int c,
              Node* nd) {
        int idx = r * B[0].size() + c;
        if (visited.count(idx) || !nd) return;
        visited.insert(idx);

        if (nd->isWord) {
            found.insert(path);
            // we do NOT clear nd->isWord, because longer words may extend this node
        }

        static int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= B.size() || nc < 0 || nc >= B[0].size()) continue;
            char ch = B[nr][nc];
            fill(found, path + ch, B, visited, nr, nc, nd->children[ch - 'a']);
        }
    }
};
