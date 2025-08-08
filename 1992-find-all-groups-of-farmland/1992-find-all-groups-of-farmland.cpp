class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        vector<vector<bool>> used(land.size(), vector<bool>(land[0].size(), false));
        for(int r = 0 ; r<land.size(); r++){
            for(int c = 0; c<land[0].size(); c++){
                if(land[r][c] == 1 && !used[r][c]){
                    int r1 = INT_MAX; int c1 = INT_MAX; int r2 = INT_MIN; int c2 = INT_MIN;
                    fill(r1,c1,r2,c2, land, used, r, c);
                    res.push_back({r1,c1,r2,c2});
                }
            }
        }
        return res;
    }

    void fill(int& r1, int& c1, int& r2, int& c2,vector<vector<int>>& land, vector<vector<bool>>& used, int rc, int cc ){
        if(rc<0 || rc>=land.size() || cc<0 || cc>=land[0].size())return;
        if(land[rc][cc]==0)return;
        if(used[rc][cc])return;
        used[rc][cc] = true;
        r1 = min(r1, rc); c1 = min(c1, cc);
        r2 = max(r2, rc); c2 = max(c2, cc);
        fill(r1,c1,r2,c2,land,used, rc+1, cc);
        fill(r1,c1,r2,c2,land,used, rc-1, cc);
        fill(r1,c1,r2,c2,land,used, rc, cc+1);
        fill(r1,c1,r2,c2,land,used, rc, cc-1);
    }
};