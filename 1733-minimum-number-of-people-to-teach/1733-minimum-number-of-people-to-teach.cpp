class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int, unordered_set<int>> map;
        unordered_set<int> langs;
        for(int i=0; i<languages.size(); i++){
            for(int j : languages[i]){
                langs.insert(j);
                map[i+1].insert(j);
            }
        }
        unordered_set<int> problematics;
        for(vector<int>& vect : friendships){
            if(!same(map[vect[0]], map[vect[1]])){
                problematics.insert(vect[0]);
                problematics.insert(vect[1]);
            }
        }
        int res = INT_MAX;
        for(int n : langs){
            int m = 0;
            for(int y : problematics){
                if(map[y].count(n)){
                    m++;
                }
            }
            int curr = problematics.size()-m;
            res = min(res, curr);
        }
        return res;
    }

    bool same(auto& s1, auto& s2){
        for(int i : s1){
            if(s2.count(i)){
                return true;
            }
        }
        return false;
    }
};