class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int r=0; r<grid.size(); r++){
            if(grid[r][0] == 0){
                for(int c = 0 ;c<grid[0].size(); c++){
                    grid[r][c] = 1 - grid[r][c];
                }
            }
        }
        for(int c=0; c<grid[0].size(); c++){
            int ones = 0;
            for(int r = 0; r<grid.size(); r++){
                if(grid[r][c] == 1){
                    ones++;
                }
            }
            if(grid.size()-ones > ones){
                for(int r = 0; r<grid.size(); r++){
                    grid[r][c] = 1 - grid[r][c];

                }
            }
        }

        int res = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                // cout<<grid[r][c]<<" ";
                res+=grid[r][c]*(1<<(grid[0].size()-c-1));
            }
            cout<<endl;
        }
        return res;
    }
};