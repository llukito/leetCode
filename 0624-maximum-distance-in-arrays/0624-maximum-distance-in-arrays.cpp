class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>> all;
        for(int i=0; i<arrays.size(); i++){
            vector<int> vect = arrays[i];
            for(int n : vect){
                all.push_back({n, i});
            }
        }
        sort(all.begin(), all.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        });
        int n1 = 0;
        for(int i=all.size()-1; i>=0; i--){
            if(all[i].second != all[0].second){
                n1 = abs(all[i].first - all[0].first);
                break;
            }
        }
        int n2 = 0;
        for(int i=0; i<all.size(); i++){
            if(all[i].second != all.back().second){
                n2 = abs(all.back().first - all[i].first);
                break;
            }
        };
        return max(n1,n2);
    }
};