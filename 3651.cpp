class Solution {
public:
    const long long INF = LLONG_MAX;
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(k + 1, vector<vector<long long>>(m, vector<long long>(n, INF)));
        
        dp[0][0][0] = 0;
        int max_val = 0;
        for (const auto& row : grid) {
            for (int val : row) max_val = max(max_val, val);
        }

        for (int i = 0; i <= k; ++i) {
            if (i > 0) {
                vector<long long> best_by_val(max_val + 1, INF);
                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < n; ++c) {
                        if (dp[i-1][r][c] != INF) {
                            best_by_val[grid[r][c]] = min(best_by_val[grid[r][c]], dp[i-1][r][c]);
                        }
                    }
                }
                
                vector<long long> best_at_least(max_val + 2, INF);
                for (int v = max_val; v >= 0; --v) {
                    best_at_least[v] = min(best_at_least[v+1], best_by_val[v]);
                }

                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < n; ++c) {
                        dp[i][r][c] = min(dp[i][r][c], best_at_least[grid[r][c]]);
                    }
                }
            }
            
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[i][r][c] == INF) continue;
                    
                    if (r + 1 < m) {
                        dp[i][r+1][c] = min(dp[i][r+1][c], dp[i][r][c] + grid[r+1][c]);
                    }
                    if (c + 1 < n) {
                        dp[i][r][c+1] = min(dp[i][r][c+1], dp[i][r][c] + grid[r][c+1]);
                    }
                }
            }
        }
        
        long long ans = INF;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[i][m-1][n-1]);
        }
        
        return (int)ans;
    }
};
