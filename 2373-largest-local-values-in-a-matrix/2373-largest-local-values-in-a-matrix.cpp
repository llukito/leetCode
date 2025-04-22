class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> result(grid.size()-2, vector<int>(grid.size()-2,0));
        for(int i=0; i+2<grid.size(); i++){
            for(int j=0; j+2<grid.size(); j++){
                int max_ = INT_MIN;
                for(int r=i; r<i+3; r++){
                    for(int c=j; c<j+3; c++){
                        max_ = max(max_, grid[r][c]);
                    }
                }
                result[i][j]=max_;
            }
        }
        return result;
    }
};