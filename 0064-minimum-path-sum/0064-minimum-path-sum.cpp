class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1, vector<int>(grid[0].size()+1,-1));
        return fill(0,0,grid, dp);
    }
    
    int fill(int r, int c, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r>=grid.size() || c>=grid[0].size()){
            return INT_MAX;
        }
        if(r==grid.size()-1 && c==grid[0].size()-1){
            return grid[r][c];
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int n1= fill(r+1, c, grid, dp);
        int n2 = fill(r, c+1, grid, dp);
        return dp[r][c]=grid[r][c]+min(n1,n2);
    }
};