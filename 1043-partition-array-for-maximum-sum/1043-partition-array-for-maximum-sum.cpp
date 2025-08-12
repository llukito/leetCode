class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for(int i=1; i<=n; i++){
            int val = 0;
            for(int j=1; j<=k; j++){
                if(i-j<0)break;
                val = max(val, arr[i-j]);
                dp[i] = max(dp[i], dp[i-j]+val*j);
            }
        }
        return dp[n];
    }
};