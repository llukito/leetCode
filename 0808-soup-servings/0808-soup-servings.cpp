class Solution {
public:
    double soupServings(int n) {
        unordered_map<string,double> dp;
        return f(n,n, dp);
    }

    double f(int a, int b, unordered_map<string,double>& dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        string key = to_string(a)+"|"+to_string(b);
        if(dp.count(key)){
            return dp[key];
        }
        double r = 0.25 * (
            f(a-100, b, dp) +
            f(a-75, b-25, dp) +
            f(a-50, b-50, dp) +
            f(a-25, b-75, dp));
        return dp[key] = r;
    }

};