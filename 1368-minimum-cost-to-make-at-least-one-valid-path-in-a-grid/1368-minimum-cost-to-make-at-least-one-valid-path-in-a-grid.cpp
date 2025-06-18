class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0] = 0;
        dq.push_front({0,0});

        // directions: right, left, down, up
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!dq.empty()) {
            auto [r,c] = dq.front(); dq.pop_front();
            int currCost = dist[r][c];

            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i].first;
                int nc = c + directions[i].second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                // cost 0 if grid[r][c] points to (nr, nc), else cost 1
                int cost = (grid[r][c] == i+1) ? 0 : 1;

                if (dist[nr][nc] > currCost + cost) {
                    dist[nr][nc] = currCost + cost;
                    if (cost == 0)
                        dq.push_front({nr,nc});
                    else
                        dq.push_back({nr,nc});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
