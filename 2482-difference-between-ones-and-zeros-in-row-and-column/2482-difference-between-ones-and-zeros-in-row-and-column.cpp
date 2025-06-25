class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow; vector<int> zerosRow;
        for(int i=0; i<grid.size(); i++){
            int ones = 0;
            for(int j : grid[i]){
                if(j==1){
                    ones++;
                }
            }
            onesRow.push_back(ones);
            zerosRow.push_back(grid[i].size()-ones);
        }
        vector<int> onesCol; vector<int> zerosCol;
        for(int i=0; i<grid[0].size(); i++){
            int ones = 0;
            for(int j=0; j<grid.size(); j++){
                if(grid[j][i]==1){
                    ones++;
                }
            }
            onesCol.push_back(ones);
            zerosCol.push_back(grid.size()-ones);
        }
        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                diff[r][c] = onesRow[r] + onesCol[c]-zerosRow[r]-zerosCol[c];
            }
        }
        return diff;
    }
};