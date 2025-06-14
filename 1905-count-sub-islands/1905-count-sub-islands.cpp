class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        set<pair<int,int>> st;
        int res = 0;
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j]==1 && !st.count({i,j})){
                    st.insert({i,j});
                    bool b = true;
                    if(grid1[i][j]!=1){
                        b = false;
                    }
                    dfs(i, j, grid2, st, b, grid1);
                    if(b){
                        res++;
                    }
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, vector<vector<int>>& grid2, set<pair<int,int>>& st, bool& b, vector<vector<int>>& grid1){
        if(i+1 < grid2.size() && grid2[i+1][j] == 1 && !st.count({i+1, j})){
            st.insert({i+1, j});
            if(grid1[i+1][j]!=1){
                b = false;
            }
            dfs(i+1, j, grid2, st, b, grid1);
        }
        if(i-1 >=0  && grid2[i-1][j] == 1 && !st.count({i-1, j})){
            st.insert({i-1, j});
            if(grid1[i-1][j]!=1){
                b = false;
            }
            dfs(i-1, j, grid2, st,b,  grid1);
        }
        if(j+1 < grid2[0].size() && grid2[i][j+1] == 1 && !st.count({i, j+1})){
            st.insert({i, j+1});
            if(grid1[i][j+1]!=1){
                b = false;
            }
            dfs(i, j+1, grid2, st,b,  grid1);
        }
        if(j-1 >=0  && grid2[i][j-1] == 1 && !st.count({i, j-1})){
            st.insert({i, j-1});
            if(grid1[i][j-1]!=1){
                b = false;
            }
            dfs(i, j-1, grid2, st,b, grid1);
        }
    }
};