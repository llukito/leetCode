class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> res(grid[0].size());
        for(auto& en : grid){
            for(int i = 0; i < en.size(); i++){
                res[i] = max(res[i], (int)to_string(en[i]).size());
            }
        }
        return res;
    }
};
