class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int cols = grid[0].size(); int rows = grid.size();
        vector<long long> prefixCols(cols, 0);
        vector<long long> prefixRows(rows, 0);
        long long allSum = 0;
        for(int r = 0; r < grid.size(); r++){
            long long val = 0;
            for(int c = 0; c < grid[0].size(); c++){
                allSum+=grid[r][c];
                val+=grid[r][c];
            }
            if(r == 0){
                prefixRows[r] = val;
            } else {
                prefixRows[r] = prefixRows[r-1] + val;
            }
        }
        for(int c = 0; c < grid[0].size(); c++){
            long long val = 0;
            for(int r = 0; r < grid.size(); r++){
                val+=grid[r][c];
            }
            if(c == 0){
                prefixCols[c] = val;
            } else {
                prefixCols[c] = prefixCols[c-1] + val;
            }
        }
        for(int r = 0; r < rows; r++){
            if(allSum - prefixRows[r] == prefixRows[r])return true;
        }
        for(int c = 0; c < cols; c++){
            if(allSum - prefixCols[c] == prefixCols[c])return true;
        }
        return false;
    }
};
