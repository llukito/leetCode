class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size();
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCross(row, col, cells, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < day; ++i) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int c = 0; c < col; ++c) {
            if (grid[0][c] == 0 && !visited[0][c]) {
                if (dfs(grid, visited, 0, c)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || 
            grid[r][c] == 1 || visited[r][c]) return false;
        
        if (r == grid.size() - 1) return true;
        
        visited[r][c] = true;
        return dfs(grid, visited, r + 1, c) || 
               dfs(grid, visited, r - 1, c) || 
               dfs(grid, visited, r, c + 1) || 
               dfs(grid, visited, r, c - 1);
    }
};
