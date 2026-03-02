class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] rightmost = new int[n];

        for (int r = 0; r < n; r++) {
            int rm = -1;
            for (int c = n - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    rm = c;
                    break;
                }
            }
            rightmost[r] = rm;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && rightmost[j] > i) j++;
            if (j == n) return -1; 
            while (j > i) {
                int tmp = rightmost[j];
                rightmost[j] = rightmost[j - 1];
                rightmost[j - 1] = tmp;
                swaps++;
                j--;
            }
        }

        return swaps;

    }
}
