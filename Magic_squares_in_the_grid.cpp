class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) return 0;
        int res = 0;
        for(int r = 0; r < grid.size()-2; r++){
            for(int c = 0; c < grid[0].size()-2; c++){
                if(validSums(grid, r, c) && from1to9(grid, r, c))res++;
            }
        }
        return res;
    }

    bool validSums(auto& grid, int r, int c){
        // check rows
        int first = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        if(first != grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2])return false;
        if(first != grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2])return false;
        // check cols
        if(first != grid[r][c] + grid[r+1][c] + grid[r+2][c])return false;
        if(first != grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1])return false;
        if(first != grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2])return false;
        // check diagonals
        if(first != grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2])return false;
        if(first != grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c])return false;

        return true;
    }

    bool from1to9(auto& grid, int r, int c){
        int arr[10] = {0};
        arr[0] = 1;
        for(int row = r; row < r+3; row++){
            for(int col = c; col < c +3; col++){
                if(grid[row][col] < 1 || grid[row][col] > 9)return false;
                arr[grid[row][col]]++;
            }
        }
        for(int i : arr){
            if(i == 0)return false;
        }
        return true;
    }
};
