class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int all = 0;
        queue<tuple<int,int,int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    all++;
                } else if(grid[i][j] == 2){
                    q.push(make_tuple(i,j,0,0));
                }
            }
        }
        if(all == 0) return 0;
        while(!q.empty()){
            auto [i, j, t, trans] = q.front(); q.pop();
            if(trans){
                all--;
            }
            if(all == 0){
                return t;
            }
            if(i+1 < grid.size() && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                q.push(make_tuple(i+1, j, t+1, 1));
            }
            if(j+1 < grid[0].size() && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                q.push(make_tuple(i, j+1, t+1, 1));
            }
            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                q.push(make_tuple(i-1, j, t+1, 1));
            }
            if(j-1 >=0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                q.push(make_tuple(i, j-1, t+1, 1));
            }
        }
        return -1;
    }
};