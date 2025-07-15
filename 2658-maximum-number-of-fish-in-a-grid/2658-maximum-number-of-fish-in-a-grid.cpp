class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(!visited[r][c] && grid[r][c]>0){
                    int num = 0;
                    check(grid, num, visited, r, c);
                    res = max(res, num);
                }
            }
        }
        return res;
    }

    void check(vector<vector<int>>& grid, int& num, vector<vector<int>>& visited, int row, int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())return;
        if(grid[row][col] == 0)return;
        if(visited[row][col])return;
        num+=grid[row][col];
        visited[row][col] = true;
        check(grid, num, visited, row+1, col);
        check(grid, num, visited, row-1, col);
        check(grid, num, visited, row, col-1);
        check(grid, num, visited, row, col+1);
    }
};