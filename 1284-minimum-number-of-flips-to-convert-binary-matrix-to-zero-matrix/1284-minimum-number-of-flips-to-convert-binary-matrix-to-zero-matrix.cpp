class Solution {
public:
    int rows = -1;
    int cols = -1;

    int minFlips(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();

        string start = encode(mat);
        string zero(rows * cols, '0');
        if (start == zero) return 0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);       
        int res = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                string curr = q.front(); q.pop();
                if (curr == zero) return res;

                for (int r = 0; r < rows; ++r) {
                    for (int c = 0; c < cols; ++c) {
                        string state = curr;
                        flip(state, r, c);      
                        if (!visited.count(state)) {
                            visited.insert(state);
                            q.push(state);
                        }
                    }
                }
            }
            ++res;
        }
        return -1;
    }

    string encode(const vector<vector<int>>& mat) {
        string s;
        s.reserve(rows * cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                s.push_back(mat[i][j] ? '1' : '0');
            }
        }
        return s;
    }


    void toggle(string &s, int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) return;
        int idx = i * cols + j;
        s[idx] = (s[idx] == '0') ? '1' : '0';
    }

    void flip(string &state, int i, int j) {
        toggle(state, i, j);
        toggle(state, i - 1, j);
        toggle(state, i + 1, j);
        toggle(state, i, j - 1);
        toggle(state, i, j + 1);
    }
};
