class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> maxHealth(rows, vector<int>(cols, -1));  // Track best remaining health

        queue<tuple<int, int, int>> q;
        int startHealth = health - grid[0][0];
        if (startHealth < 0) return false;

        q.push({0, 0, startHealth});
        maxHealth[0][0] = startHealth;

        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            auto [r, c, h] = q.front(); q.pop();
            if(h<1)continue;
            if (r == rows - 1 && c == cols - 1) return true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int nextHealth = h - grid[nr][nc];
                    if (nextHealth >= 0 && nextHealth > maxHealth[nr][nc]) {
                        maxHealth[nr][nc] = nextHealth;
                        q.push({nr, nc, nextHealth});
                    }
                }
            }
        }

        return false;
    }
};
