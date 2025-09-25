class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                dp[i][j] = triangle[i][j] + min(i+1<n ? dp[i+1][j] : 0, i+1<n ? dp[i+1][j+1] : 0);
            }
        }
        return dp[0][0];
    }
};