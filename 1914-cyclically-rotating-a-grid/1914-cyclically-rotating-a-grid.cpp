class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < min(rows, cols) / 2; i++) {
            vector<int> vect;
            getVect(grid, vect, i, i, rows - 1 - i, cols - 1 - i);
            int kk=k%vect.size();
            rotate(vect.begin(), vect.begin() + kk, vect.end());
            fill(grid, vect, i, i, rows - 1 - i, cols - 1 - i);
        }
        
        return grid;
    }

    void fill(vector<vector<int>>& grid, vector<int>& vect, int sR, int sC, int eR, int eC) {
        int ind = 0;
        for (int c = sC; c <= eC; c++) {
            grid[sR][c] = vect[ind++];
        }
        for (int r = sR + 1; r <= eR; r++) {
            grid[r][eC] = vect[ind++];
        }
        for (int c = eC - 1; c >= sC; c--) {
            grid[eR][c] = vect[ind++];
        }
        for (int r = eR - 1; r > sR; r--) {
            grid[r][sC] = vect[ind++];
        }
    }

    void getVect(vector<vector<int>>& grid, vector<int>& vect, int sR, int sC, int eR, int eC) {
        for (int c = sC; c <= eC; c++) {
            vect.push_back(grid[sR][c]);
        }
        for (int r = sR + 1; r <= eR; r++) {
            vect.push_back(grid[r][eC]);
        }
        for (int c = eC - 1; c >= sC; c--) {
            vect.push_back(grid[eR][c]);
        }
        for (int r = eR - 1; r > sR; r--) {
            vect.push_back(grid[r][sC]);
        }
    }
};