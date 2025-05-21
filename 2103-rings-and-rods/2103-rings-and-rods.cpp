class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, unordered_set<char>> map;
        for(int i=0; i<rings.size(); i+=2){
            map[rings[i+1]-'0'].insert(rings[i]);
        }
        int num = 0;
        for(auto& entry : map){
            if(entry.second.size() == 3)num++;
        }
        return num;
    }
};