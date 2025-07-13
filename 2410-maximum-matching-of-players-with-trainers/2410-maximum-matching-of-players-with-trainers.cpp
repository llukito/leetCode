class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        vector<pair<int,int>> vect;
        for(int n : players){
            vect.push_back({n,0});
        }
        for(int n : trainers){
            vect.push_back({n,1});
        }
        sort(vect.begin(), vect.end());
        int count = 0;
        int res = 0;
        for(int i=0; i<vect.size(); i++){
            if(vect[i].second == 1){
                if(count>0){
                    count--;
                    res++;
                }
            } else {
                count++;
            }
        }
        return res;
    }
};