class Solution {
    public int[][] constructProductMatrix(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int total = n * m;
        final int MOD = 12345;

        int[] flat = new int[total];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                flat[i * m + j] = grid[i][j] % MOD;

        int[] prefix = new int[total];
        prefix[0] = 1;
        for (int k = 1; k < total; k++)
            prefix[k] = (int)((long) prefix[k-1] * flat[k-1] % MOD);

        int[] suffix = new int[total];
        suffix[total - 1] = 1;
        for (int k = total - 2; k >= 0; k--)
            suffix[k] = (int)((long) suffix[k+1] * flat[k+1] % MOD);

        int[][] result = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int k = i * m + j;
                result[i][j] = (int)((long) prefix[k] * suffix[k] % MOD);
            }

        return result;
    }
}
