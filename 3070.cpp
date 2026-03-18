class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size(); int cols = grid[0].size();
        vector<vector<int>> prefixes(rows, vector<int>(cols, 0));
        // should take around 1 sec
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int top = r-1 >= 0 ? prefixes[r-1][c] : 0;
                int left = c-1 >= 0 ? prefixes[r][c-1] : 0;
                int rem = (r-1 >= 0 && c-1 >= 0) ? prefixes[r-1][c-1] : 0;
                prefixes[r][c] = top + left - rem + grid[r][c];
            }
        }
        int res = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(prefixes[r][c] <= k)res++;
            }
        }
        return res;
    }
};
