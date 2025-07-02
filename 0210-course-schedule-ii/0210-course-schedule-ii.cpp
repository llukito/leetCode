class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        for(vector<int> vec : prerequisites){
            map[vec[0]].push_back(vec[1]);
        }
        vector<int> res;
        unordered_set<int> visited;
        for(int i=0; i<numCourses; i++){
            if(!visited.count(i)){
                if(!fill(visited, res, map, i)){
                    return vector<int>();
                }
            }
        }
        return res;
    }

    bool fill(unordered_set<int>& visited, vector<int>& res, unordered_map<int, vector<int>>& map, int cor){
        if(find(res.begin(), res.end(), cor)!=res.end()){
            return true;
        }
        if(visited.count(cor)){
            return false;
        }
        visited.insert(cor);
        if(!map.count(cor)){
            res.push_back(cor);
            return true;
        }
        for(int n : map[cor]){
            if(!fill(visited, res, map, n)){
                return false;
            }
        }
        res.push_back(cor);
        return true;
    }
};