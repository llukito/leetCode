class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0;

        unordered_map<int, long long> gainMap;
        for (int x : power) gainMap[x] += x;

        vector<int> vals;
        vals.reserve(gainMap.size());
        for (auto& p : gainMap) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> gain(n), dp(n, 0);
        for (int i = 0; i < n; ++i) gain[i] = gainMap[vals[i]];

        for (int i = 0; i < n; ++i) {
            long long take = gain[i];
            int j = upper_bound(vals.begin(), vals.begin() + i, vals[i] - 3) - vals.begin() - 1;
            if (j >= 0) take += dp[j];
            long long skip = (i > 0 ? dp[i - 1] : 0);
            dp[i] = max(skip, take);
        }

        return dp.back();
    }
};
