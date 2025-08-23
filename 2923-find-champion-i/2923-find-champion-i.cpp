class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for(int c = 0; c<grid[0].size(); c++){
            bool b = true;
            for(int r=0; r<grid.size(); r++){
                if(grid[r][c]==1){
                    b = false;
                    break;
                }
            }
            if(b)return c;
        }
        return -1;
    }
};