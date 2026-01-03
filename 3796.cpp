class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> a(n, INT_MAX);
        a[0] = 0;
        for (auto& r : restrictions) {
            a[r[0]] = min(a[r[0]], r[1]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != INT_MAX) {
                a[i + 1] = min(a[i + 1], a[i] + diff[i]);
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (a[i + 1] != INT_MAX) {
                a[i] = min(a[i], a[i + 1] + diff[i]);
            }
        }

        int ans = 0;
        for (int x : a) {
            ans = max(ans, x);
        }
        return ans;
    }
};
