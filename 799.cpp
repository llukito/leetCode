class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, 0));
        dp[0][0] = poured;
        int cols = 2;
        for(int r = 1; r < 100; r++){
            for(int c = 0; c < cols; c++){
                if(c == 0 || c == cols-1){
                    double curr = (dp[r-1][c == 0 ? c : c-1]-1)/(double)2.0;
                    dp[r][c] = curr > 0 ? curr : 0;
                } else {
                    double curr1 = (dp[r-1][c-1]-1)/(double)2.0;
                    double curr2 = (dp[r-1][c]-1)/(double)2.0;
                    dp[r][c] += curr1 > 0 ? curr1 : 0;
                    dp[r][c] += curr2 > 0 ? curr2 : 0;
                }
            }
            cols++;
        }
        double res = dp[query_row][query_glass];
        return res > 1 ? 1 : res ;
    }
};
