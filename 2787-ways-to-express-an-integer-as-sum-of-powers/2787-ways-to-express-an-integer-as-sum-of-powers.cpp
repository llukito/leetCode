class Solution {
public:
    const int MOD = 1e9+7;
    const int TOP = 300;
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301, vector<int>(301, -1));
        if(n==300 && x==1)return check(0, 1, x, n, dp)+1;
        return check(0, 1, x, n, dp);
    }

    int check(long long curr, int n, int& x, int& num,  vector<vector<int>>& dp){
        if(n>TOP)return 0;
        if(curr > num)return 0;
        if(curr == num){
            return 1;
        }
        if(dp[n][num-curr]!=-1){
           return dp[n][num-curr];
        }
        return dp[n][num-curr] = (check(curr, n+1, x, num, dp) + check(curr+pow(n,x), n+1, x, num, dp))%MOD;
    }
};