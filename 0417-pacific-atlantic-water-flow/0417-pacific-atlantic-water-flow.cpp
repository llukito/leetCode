class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size() , vector<int>(heights[0].size(), 0));
        for(int r=0; r<heights.size(); r++){
            vector<vector<bool>> visited(heights.size() , vector<bool>(heights[0].size(), 0));
            dfs(r, 0, visited, pacific, heights, 0);
        }
        for(int c=0; c<heights[0].size(); c++){
            vector<vector<bool>> visited(heights.size() , vector<bool>(heights[0].size(), 0));
            dfs(0, c, visited, pacific, heights, 0);
        }

        vector<vector<int>> atlantic(heights.size() , vector<int>(heights[0].size(), 0));
        for(int r=0; r<heights.size(); r++){
            vector<vector<bool>> visited(heights.size() , vector<bool>(heights[0].size(), 0));
            dfs(r, heights[0].size()-1, visited, atlantic, heights, 0);
        }
        for(int c=0; c<heights[0].size(); c++){
            vector<vector<bool>> visited(heights.size() , vector<bool>(heights[0].size(), 0));
            dfs(heights.size()-1, c, visited, atlantic, heights, 0);
        }

        vector<vector<int>> result;
        for(int r=0; r<heights.size(); r++){
            for(int c = 0; c<heights[0].size(); c++){
                // cout<<pacific[r][c]<<" pacific"<<endl;
                cout<<atlantic[r][c]<<" atlantic"<<endl;
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r,c});
                }
            }
            cout<<endl;
        }
        return result;
    }

    void dfs(int r, int c,
         vector<vector<bool>>& visited,
         vector<vector<int>>& ocean,
         vector<vector<int>>& heights,
         int prevHeight) {
    int m = heights.size(), n = heights[0].size();
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (visited[r][c]) return;
    if (heights[r][c] < prevHeight) return; 

    visited[r][c] = true;
    ocean[r][c] = 1;

    dfs(r+1, c, visited, ocean, heights, heights[r][c]);
    dfs(r-1, c, visited, ocean, heights, heights[r][c]);
    dfs(r, c+1, visited, ocean, heights, heights[r][c]);
    dfs(r, c-1, visited, ocean, heights, heights[r][c]);
    }
};