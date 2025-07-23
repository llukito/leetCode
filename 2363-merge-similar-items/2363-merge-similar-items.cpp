class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
       map<int,int> mp;
        for(auto& entry : items1){
            mp[entry[0]]+= entry[1];
        }
        for(auto& entry : items2){
            mp[entry[0]]+= entry[1];
        }
        vector<vector<int>> v;
        for(auto& entry : mp){
            v.push_back({entry.first, entry.second});
        }
        return v;
    }
};