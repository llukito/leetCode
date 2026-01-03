class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfRoutes(vector<string>& grid, int d) {
        int R = grid.size();
        int C = grid[0].size();
        vector<long long> total(C, 0);

        vector<long long> vert(C, 0);
        for (int j = 0; j < C; j++) {
            if (grid[R - 1][j] == '.') vert[j] = 1;
        }

        vector<long long> horiz(C, 0);
        long long current = 0;
        for (int k = 0; k <= min(C - 1, d); ++k) {
            current = (current + vert[k]) % MOD;
        }

        for (int j = 0; j < C; j++) {
            if (grid[R - 1][j] == '.') {
                horiz[j] = (current - vert[j] + MOD) % MOD;
            }
            if (j - d >= 0) current = (current - vert[j - d] + MOD) % MOD;
            if (j + 1 + d < C) current = (current + vert[j + 1 + d]) % MOD;
        }

        for (int j = 0; j < C; j++) total[j] = (vert[j] + horiz[j]) % MOD;

        for (int i = R - 2; i >= 0; --i) {
            int lim = 0;
            long long d2 = 1ll * d * d;
            if (d2 > 1) lim = floor(sqrt(d2 - 1));

            vector<long long> nextVert(C, 0);
            current = 0;
            for (int k = 0; k <= min(C - 1, lim); k++) {
                current = (current + total[k]) % MOD;
            }

            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '.') {
                    nextVert[j] = current;
                }
                if (j - lim >= 0) current = (current - total[j - lim] + MOD) % MOD;
                if (j + 1 + lim < C) current = (current + total[j + 1 + lim]) % MOD;
            }

            vector<long long> nextHoriz(C, 0);
            current = 0;
            for (int k = 0; k <= min(C - 1, d); ++k) {
                current = (current + nextVert[k]) % MOD;
            }

            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '.') {
                    nextHoriz[j] = (current - nextVert[j] + MOD) % MOD;
                }
                if (j - d >= 0) current = (current - nextVert[j - d] + MOD) % MOD;
                if (j + 1 + d < C) current = (current + nextVert[j + 1 + d]) % MOD;
            }

            for (int j = 0; j < C; ++j) {
                total[j] = (nextVert[j] + nextHoriz[j]) % MOD;
            }
        }

        long long res = 0;
        for (long long x : total) res = (res + x) % MOD;
        return res;
    }
};
