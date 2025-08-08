class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> map;
        for(vector<int> vect : adjacentPairs){
            map[vect[0]].push_back(vect[1]);
            map[vect[1]].push_back(vect[0]);
        }
        int start = 0;
        for(auto& entry : map){
            if(entry.second.size() == 1){
                start = entry.first; break;
            }
        }
        vector<int> res;
        res.push_back(start);
        while(true){
            int n = res.back();
            int next = map[n][0];
            res.push_back(next);
            map[next].erase(find(map[next].begin(), map[next].end(), n));
            if(res.size() == map.size())break;
        }
        return res;
    }
};