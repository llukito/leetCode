class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> map;
        for(vector<int> vect : logs){
            map[vect[0]].insert(vect[1]);
        }
        vector<int> res(k, 0);
        for(auto& entry : map){
            res[entry.second.size()-1]++;
        }
        return res;
    }
};