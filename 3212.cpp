class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(); int cols = grid[0].size();
        vector<vector<int>> prefixes(rows, vector<int>(cols, 0));
        vector<vector<bool>> bools(rows, vector<bool>(cols, false));
        // should take around 1 sec
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int top = r-1 >= 0 ? prefixes[r-1][c] : 0;
                int left = c-1 >= 0 ? prefixes[r][c-1] : 0;
                int rem = (r-1 >= 0 && c-1 >= 0) ? prefixes[r-1][c-1] : 0;
                prefixes[r][c] = top + left - rem + ((grid[r][c] == 'X') ? 1 : (grid[r][c] == 'Y') ? -1 : 0);
                if(grid[r][c] != '.')bools[r][c] = true;
                if(r-1 >= 0 && bools[r-1][c])bools[r][c] = true;
                if(c-1 >= 0 && bools[r][c-1])bools[r][c] = true;
            }
        }
        int res = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(prefixes[r][c] == 0 && bools[r][c])res++;
            }
        }
        return res;
    }
};
