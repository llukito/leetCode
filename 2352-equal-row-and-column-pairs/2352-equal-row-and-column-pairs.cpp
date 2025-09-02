class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int, string> mapRows;
        for(int r=0; r<grid.size(); r++){
            string key = "";
            for(int c=0; c<grid[0].size(); c++){
                key+=to_string(grid[r][c]);
                key+="|";
            }
            mapRows[r] = key;
        }
        unordered_map<int, string> mapCols;
        for(int c=0; c<grid[0].size(); c++){
            string key = "";
            for(int r=0; r<grid.size(); r++){
                key+=to_string(grid[r][c]);
                key+="|";
            }
            mapCols[c] = key;
        }
        int res = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(mapRows[r] == mapCols[c])res++;
            }
        }
        return res;
    }
};