class Solution {
public:
    int all = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> dp(grid.size(), vector<bool>(grid[0].size(), false));
        for(int r=0; r<grid.size(); r++){
            for(int c =0 ; c<grid[0].size(); c++){
                if(grid[r][c] == 1 && !dp[r][c]){
                    bool b = false;
                    check(r, c, grid,dp, b);
                    if(!b){
                        res+=all;
                    }
                    all = 0;
                }
            }
        }
        return res;
    }

    void check(int r, int c, auto& grid, auto& dp, bool& b){
        dp[r][c] = true;
        all++;
        if(r+1>=grid.size() || r-1<0 || c-1<0 || c+1>=grid[0].size()){
            b = true;
        }
        if(r+1<grid.size() && grid[r+1][c] == 1 && !dp[r+1][c]){
            check(r+1, c, grid, dp, b);
        }
        if(r-1>=0 && grid[r-1][c] == 1 && !dp[r-1][c]){
            check(r-1, c, grid, dp, b);
        }
        if(c+1<grid[0].size() && grid[r][c+1] == 1 && !dp[r][c+1]){
            check(r, c+1, grid, dp, b);
        }
        if(c-1>=0 && grid[r][c-1] == 1 && !dp[r][c-1]){
            check(r, c-1, grid, dp, b);
        }
    }
};