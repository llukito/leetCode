class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m, vector<long long>(k, 0)));
        dp[0][0][grid[0][0]%k]++;
        for(int c = 0; c < m; c++){
            for(int r = 0; r < n; r++){
                if(c == 0 && r == 0)continue;
                if(c-1 >= 0){
                    for(int i = 0; i < k; i++){
                        dp[r][c][(i+grid[r][c])%k] += dp[r][c-1][i];
                        dp[r][c][(i+grid[r][c])%k] %= MOD;
                    }
                }
                if(r-1 >= 0){
                    for(int i = 0; i < k; i++){
                        dp[r][c][(i+grid[r][c])%k] += dp[r-1][c][i];
                        dp[r][c][(i+grid[r][c])%k] %= MOD;
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};