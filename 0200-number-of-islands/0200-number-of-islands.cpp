class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> bools(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(!bools[r][c] && grid[r][c]=='1'){
                    fillBools(bools,grid, r, c);
                    res++;
                }
            }
        }
        return res;
    }

    void fillBools(vector<vector<bool>>& bools, vector<vector<char>>& grid, int r, int c ){
        bools[r][c] = true;
        if(r+1<bools.size() && grid[r+1][c] == '1' && !bools[r+1][c]){
            fillBools(bools,grid, r+1, c);
        }
        if(c+1<bools[0].size() && grid[r][c+1] == '1' && !bools[r][c+1]){
            fillBools(bools,grid, r, c+1);
        }
        if(r-1 >= 0 && grid[r-1][c] == '1' && !bools[r-1][c]){
            fillBools(bools,grid, r-1, c);
        }
        if(c-1 >= 0 && grid[r][c-1] == '1' && !bools[r][c-1]){
            fillBools(bools,grid, r, c-1);
        }
    }
};