class Solution {
public:
    struct Node {
        Node* children[26];
        bool isWord;
        Node() : isWord(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    Node* root;

    void addRec(Node*& node, const string& w, int i) {
        if (!node) node = new Node();
        if (i == w.size()) {
            node->isWord = true;
            return;
        }
        addRec(node->children[w[i]-'a'], w, i+1);
    }

    void addWord(const string& w) {
        addRec(root, w, 0);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for (auto& w : words) addWord(w);
        
        int R = board.size(), C = board[0].size();
        unordered_set<string> found;
        vector<vector<bool>> seen(R, vector<bool>(C, false));

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                char ch = board[r][c];
                Node* nd = root->children[ch - 'a'];
                if (nd) dfs(board, r, c, nd, string(1, ch), seen, found);
            }
        }
        return { found.begin(), found.end() };
    }

    void dfs(vector<vector<char>>& B, int r, int c, Node* nd,
             string curr, vector<vector<bool>>& seen,
             unordered_set<string>& found) {
        if (!nd) return;
        if (nd->isWord) {
            found.insert(curr);
            nd->isWord = false;
        }

        seen[r][c] = true;
        static int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr<0||nr>=B.size()||nc<0||nc>=B[0].size()|| seen[nr][nc]) continue;
            char nch = B[nr][nc];
            dfs(B, nr, nc, nd->children[nch - 'a'], curr + nch, seen, found);
        }

        seen[r][c] = false;  // backtrack
    }
};
