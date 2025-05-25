class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> map;
        for(int i=0; i<stones.size(); i++){
            for(int j = i+1; j<stones.size(); j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        vector<bool> bools(stones.size(), false);
        int components = 0;
        for(int i=0; i<stones.size(); i++){
            if(!bools[i]){
                bools[i] = true;
                dfs(i, bools, map);
                components++;
            }
        }
        return stones.size()-components;
    }

    void dfs(int i, vector<bool>& bools, unordered_map<int, vector<int>>& map){
        for(int n : map[i]){
            if(!bools[n]){
                bools[n] = true;
                dfs(n, bools, map);
            }
        }
    }
};