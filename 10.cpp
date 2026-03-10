class Solution {
public:
    vector<vector<int>> dp;
    
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 2, -1));
        return match(s, p, 0, 1, p[0]);
    }

    bool match(auto& s, auto& p, int i, int j, char ch) {
        if(i == s.size() && j-1 == p.size()) return true;
        
        if(j - 1 > p.size()) return false;
        
        if(dp[i][j] != -1) return dp[i][j];

        char next_ch = j < p.size() ? p[j] : '\0';
        
        if(ch == '*') return dp[i][j] = match(s, p, i, j+1, next_ch);
        
        if(j >= p.size() || p[j] != '*'){
            if(i < s.size() && (s[i] == ch || ch == '.')){
                return dp[i][j] = match(s, p, i+1, j+1, next_ch);
            } else {
                return dp[i][j] = 0;
            }
        } else if(p[j] == '*'){
            for(int k = i; k < s.size(); k++){
                if(ch == s[k] || ch == '.'){
                    if(match(s, p, k+1, j+1, next_ch)) return dp[i][j] = 1;
                } else {
                    break;
                }
            }
        }
        
        return dp[i][j] = match(s, p, i, j+1, next_ch);
    }
};
