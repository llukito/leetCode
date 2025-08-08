class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                if(r+2 < grid.size() && c+2<grid[0].size()){
                    int curr = 0;
                    for(int i=c; i<c+3; i++){
                        curr+=grid[r][i];
                    }
                    curr+=grid[r+1][c+1];
                    for(int i=c; i<c+3; i++){
                        curr+=grid[r+2][i];
                    }
                    res = max(res, curr);
                }
            }
        }
        return res;
    }
};