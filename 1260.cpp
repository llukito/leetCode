class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> res(rows, vector(cols, 0));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int rr = (c+k)/cols;
                int cc = k - (rr*cols - c);
                res[(r+rr)%rows][cc%cols] = grid[r][c];
            }
        }
        return res;
    }
};
