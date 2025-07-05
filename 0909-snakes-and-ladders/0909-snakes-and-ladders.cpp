class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [cell, moves] = q.front(); q.pop();

            if (cell == n * n) return moves;

            for (int i = 1; i <= 6 && cell + i <= n * n; ++i) {
                int next = cell + i;
                auto [r, c] = getPosition(next, n);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }

    pair<int, int> getPosition(int num, int n) {
        int quot = (num - 1) / n;
        int rem = (num - 1) % n;
        int row = n - 1 - quot;
        int col = (quot % 2 == 0) ? rem : n - 1 - rem;
        return {row, col};
    }
};
