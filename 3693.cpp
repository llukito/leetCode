class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            apply(i, i+1, dp, costs);
            apply(i, i+2, dp, costs);
            apply(i, i+3, dp, costs);
        }
        return dp[n];
    }

    void apply(int i, int j, auto& dp, auto& costs){
        if(j < dp.size()){
            dp[j] = min(dp[j], dp[i] + costs[j-1] + (j - i)*(j - i));
        }
    }
};
