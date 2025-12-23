class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], events[i][2]);
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;
            int target = events[i][1] + 1;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] >= target)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            res = max(res, events[i][2] + dp[lo]);
        }

        return res;
    }
};
