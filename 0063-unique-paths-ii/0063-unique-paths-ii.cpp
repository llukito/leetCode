class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)return 0;
        vector<vector<int>> dp(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1,-1));
        return numPathsHome(0,0, dp, obstacleGrid);
    }

    int numPathsHome(int currS, int currA, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if (currS==obstacleGrid.size()-1 && currA==obstacleGrid[0].size()-1)  {
            return 1;
        }
        if (currS>=obstacleGrid.size() || currA>=obstacleGrid[0].size()) {
            return 0;
        }
        if(obstacleGrid[currS][currA]==1)return 0;
        if(dp[currS][currA]!=-1)return dp[currS][currA];
        dp[currS][currA] = numPathsHome(currS+1, currA, dp, obstacleGrid) + numPathsHome(currS, currA+1, dp, obstacleGrid);
        return dp[currS][currA];
    }
};