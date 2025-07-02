class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int possibleStringCount(string word, int k) {
        vector<int> groups;
        int n = word.size();
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            groups.push_back(j - i);
            i = j;
        }

        int maxLen = word.size();
        vector<vector<int>> dp(groups.size() + 1, vector<int>(maxLen + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < groups.size(); ++i) {
            int runLength = groups[i];
            for (int prevLen = 0; prevLen <= maxLen; ++prevLen) {
                if (dp[i][prevLen] == 0) continue;
                for (int use = 1; use <= runLength; ++use) {
                    dp[i + 1][prevLen + use] = (dp[i + 1][prevLen + use] + dp[i][prevLen]) % MOD;
                }
            }
        }

        int result = 0;
        for (int l = k; l <= maxLen; ++l) {
            result = (result + dp[groups.size()][l]) % MOD;
        }

        return result;
    }
}; 