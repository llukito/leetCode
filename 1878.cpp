class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> sums;
        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                add(sums, grid[r][c]);

                for (int k = 1; ; k++) {
                    if (r + 2 * k >= m || c - k < 0 || c + k >= n) break;

                    int curr = 0;
                    for (int i = 0; i < k; i++) {
                        curr += grid[r + i][c + i];
                        curr += grid[r + k + i][c + k - i];
                        curr += grid[r + 2 * k - i][c - i];
                        curr += grid[r + k - i][c - k + i];
                    }
                    add(sums, curr);
                }
            }
        }

        return vector<int>(sums.rbegin(), sums.rend());
    }

private:
    void add(set<int>& sums, int val) {
        sums.insert(val);
        if (sums.size() > 3) {
            sums.erase(sums.begin());
        }
    }
};
