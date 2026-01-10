class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int all = 0;
        for(char ch : s1)all+=ch;
        for(char ch : s2)all+=ch;
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < s2.size(); j++){
                if(s1[i] == s2[j]){
                    if((i-1)<0 || (j-1)<0)dp[i][j] =  s1[i];
                    else dp[i][j] =  s1[i] + dp[i-1][j-1];
                } else {
                    int r1 = 0, r2 = 0;
                    if((i-1)>=0)r1=dp[i-1][j];
                    if((j-1)>=0)r2=dp[i][j-1];
                    dp[i][j] = max(r1, r2);
                }
            }
        }
        return all - 2*dp[s1.size()-1][s2.size()-1];
    }
};
