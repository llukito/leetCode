class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), true));
        for(int i=0; i<grid[0].size(); i++){
            int mm = INT_MIN;
            for(int r=0; r<grid.size(); r++){
                int col = -1; int max_ = INT_MIN;   
                for(int c=0; c<grid[0].size(); c++){
                    if(visited[r][c] && max_ < grid[r][c]){
                        max_ = grid[r][c];
                        col = c;
                    }
                }
                visited[r][col] = false;
                mm = max(mm, max_);
            }
            res+=mm;
        }
        return res;
    }
};