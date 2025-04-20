class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int,int> mp;
        for(int i=0; i<score.size(); i++){
            auto vec = score[i];
            mp[vec[k]]=i;
        }
        vector<vector<int>> res;
        for(auto entry : mp){
            res.push_back(score[entry.second]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};