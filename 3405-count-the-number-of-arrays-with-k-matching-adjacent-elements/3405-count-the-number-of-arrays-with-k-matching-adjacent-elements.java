class Solution {
    private final int mod = 1_000_000_007;

    public int countGoodArrays(int n, int m, int k) {
        long result = m;
        result = (result * C(n - 1, k)) % mod;
        result = (result * modPow(m - 1, n - 1 - k)) % mod;
        return (int) result;
    }

    private long modPow(long base, long exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    private long modInverse(long x) {
        return modPow(x, mod - 2); 
    }   

    private int C(int n, int k) {
        if (k > n) return 0;
        long res = 1;
        for (int i = k + 1; i <= n; i++) {
            res = (res * i) % mod;
        }
        for (int i = 2; i <= n - k; i++) {
            res = (res * modInverse(i)) % mod;
        }
        return (int) res;
    }
}