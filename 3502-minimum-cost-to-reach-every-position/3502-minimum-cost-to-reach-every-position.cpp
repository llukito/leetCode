class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int min_ = cost[0];
        vector<int> mins;
        for(int i=0; i<cost.size(); i++){
            min_ = min(min_, cost[i]);
            mins.push_back(min_);
        }
        return mins;
    }
};