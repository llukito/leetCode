class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> noLoss, oneLoss;
        unordered_map<int,int> m;
        unordered_set<int> players;
        for(vector<int> vect : matches){
            players.insert(vect[0]); players.insert(vect[1]);
            m[vect[1]]++;
        }
        for(int n : players){
            if(m.count(n) && m[n]==1){
                oneLoss.push_back(n);
            } else if(!m.count(n)){
                noLoss.push_back(n);
            }
        }
        sort(noLoss.begin(), noLoss.end());
        sort(oneLoss.begin(), oneLoss.end());
        return {noLoss, oneLoss};
    }
};