class Solution {
    public int uniquePathsIII(int[][] grid) {
        int[] result = new int[1]; result[0] = 0;
        int r = 0; int c = 0; int obstacles = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 1){
                    r = i;
                    c = j;
                }
                if(grid[i][j] == -1){
                    obstacles++;
                }
            }
        }
        check(result, grid, r, c, grid[0].length * grid.length - obstacles - 1, 0);
        return result[0];
    }

    private void check(int[] result, int[][] grid, int r, int c, int expected, int curr){
        if(grid[r][c] == 2){
            if(expected != curr)return;
            result[0] = result[0]+1;
            return;
        }
        int temp = grid[r][c];
        grid[r][c] = -1;
        if(r+1 < grid.length && grid[r+1][c]!=-1){
            check(result, grid, r+1, c, expected, curr+1);
        }
        if(c+1<grid[0].length && grid[r][c+1]!=-1){
            check(result, grid, r, c+1, expected, curr+1);
        }
        if(r-1>=0 && grid[r-1][c]!=-1){
            check(result, grid, r-1, c, expected, curr+1);
        }
        if(c-1>=0 && grid[r][c-1]!=-1){
            check(result, grid, r, c-1, expected, curr+1);
        }
        grid[r][c] = temp;
    }
}