class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(); int cols = grid[0].size();
        int res = 1;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                int maxSide = min(rows-r, cols-c);
                for(int l = 1; l <= maxSide; l++){
                    if(valid(grid, r, c, l)) {
                        res = max(res, l);
                    }
                }
            }
        }
        return res;
    }

    bool valid(auto& grid, int r, int c, int l){
        int sum = -1;
        for(int j = 0; j < l; j++){
            int currSum = 0;
            for(int i = 0; i < l; i++){
                currSum+=grid[r+j][c+i];
            }
            if(sum == -1){
                sum = currSum;
            } else {
                if(sum != currSum)return false;
            }
        }

        for(int j = 0; j < l; j++){
            int currSum = 0;
            for(int i = 0; i < l; i++){
                currSum+=grid[r+i][c+j];
            }
            if(sum != currSum)return false;
        }

        int currSum = 0;
        for(int j = 0; j < l; j++){
            currSum+=grid[r+j][c+j];
        }
        if(sum != currSum)return false;
        currSum = 0;
        for(int j = 0; j < l; j++){
            currSum+=grid[r+l-1-j][c+j];
        }
        return sum == currSum;
    }
};
