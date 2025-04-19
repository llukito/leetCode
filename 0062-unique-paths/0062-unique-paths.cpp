class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return numPathsHome(m, n,dp);
    }

    int numPathsHome(int street, int avenue, vector<vector<int>>& dp) {
        if (street == 1 && avenue == 1) {
            return 1;
        }
        if (street < 1 || avenue < 1) {
            return 0;
        }
        if(dp[street][avenue]!=-1)return dp[street][avenue];
        dp[street][avenue] = numPathsHome(street - 1, avenue, dp) + numPathsHome(street, avenue - 1, dp);
        return dp[street][avenue];
}
};