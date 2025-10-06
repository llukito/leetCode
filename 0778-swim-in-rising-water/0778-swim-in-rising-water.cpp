class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto& pairs = pq.top();
            int curr = pairs.first; int r = pairs.second.first; int c = pairs.second.second;
            pq.pop();
            if(r == n-1 && c == n-1){
                return curr;
            }
            if(r+1 < n && dist[r+1][c] == -1){
                dist[r+1][c] = 1;
                pq.push({max(grid[r+1][c], curr), {r+1,c}});
            }
            if(r-1 >= 0 && dist[r-1][c] == -1){
                dist[r-1][c] = 1;
                pq.push({max(grid[r-1][c], curr), {r-1,c}});
            }
            if(c+1 < n && dist[r][c+1] == -1){
                dist[r][c+1] = 1;
                pq.push({max(grid[r][c+1], curr), {r,c+1}});
            }
            if(c-1>=0 && dist[r][c-1] == -1){
                dist[r][c-1] = 1;
                pq.push({max(grid[r][c-1], curr), {r,c-1}});
            }
        }
        return -1;
    }
};