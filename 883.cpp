class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int total_area = 0;
        total_area += top(grid);
        total_area += front(grid);
        total_area += side(grid);
        return total_area;
    }

    int top(auto& grid){
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                res += grid[r][c] != 0 ? 1 : 0;
            }
        }
        return res;
    }

    int front(auto& grid){
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            int max_ = 0;
            for(int c = 0; c < grid[0].size(); c++){
                max_ = max(max_, grid[r][c]);
            }
            res += max_;
        }
        return res;
    }

    int side(auto& grid){
        int res = 0;
        for(int c = 0; c < grid[0].size(); c++){
            int max_ = 0;
            for(int r = 0; r < grid.size(); r++){
                max_ = max(max_, grid[r][c]);
            }
            res += max_;
        }
        return res;
    }
};
