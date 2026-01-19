class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(), cols = mat[0].size();

        vector<vector<int>> pref(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                pref[i][j] = mat[i-1][j-1]
                           + pref[i-1][j]
                           + pref[i][j-1]
                           - pref[i-1][j-1];
            }
        }

        int res = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int maxSide = min(rows - r, cols - c);
                for (int l = 1; l <= maxSide; l++) {
                    int sum = pref[r+l][c+l]
                            - pref[r][c+l]
                            - pref[r+l][c]
                            + pref[r][c];

                    if (sum <= threshold)
                        res = max(res, l);
                    else
                        break; 
                }
            }
        }
        return res;
    }
};
