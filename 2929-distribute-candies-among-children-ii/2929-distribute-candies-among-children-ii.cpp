class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        limit++;
        for (int i = 0; i <= 3; i++) {
            int remaining = n - i * limit;
            if (remaining < 0) break;
            long long c1 = comb(3, i);
            long long c2 = comb(remaining + 2, 2);
            long long term = c1 * c2;
            if (i % 2 == 0) res += term;
            else res -= term;
        }
        return res;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }
};
