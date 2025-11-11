class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string s : strs){
            auto res = getStatistics(s);
            int zeros = res.first; int ones = res.second;
            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    if(i-zeros>=0 && j-ones>=0)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int,int> getStatistics(string s){
        int zeros = 0; int ones = 0;
        for(char ch : s){
            if(ch == '0'){
                zeros++;
            } else {
                ones++;
            }
        }
        return {zeros, ones};
    }
};