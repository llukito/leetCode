class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> dp(graph.size(), false);
        vector<int> result;
        check(result, graph, dp);
        return result;
    }

    void check(vector<int>& result, vector<vector<int>>& graph, vector<bool>& dp){
        for(int i=0; i<graph.size(); i++){
            vector<int> vect = graph[i];
            bool b = true;
            for(int neigh : vect){
                unordered_set<int> set;
                if(valid(graph, dp, neigh, set)){
                    continue;
                }
                b = false;
                break;
            }
            if(b){
                dp[i]=true;
                result.push_back(i);
            }
        }
    }

     bool valid(vector<vector<int>>& graph, vector<bool>& dp, int neigh, unordered_set<int>& set){
        if(set.count(neigh))return false;
        if(dp[neigh] || graph[neigh].empty())return true;
        set.insert(neigh);
        for(int n : graph[neigh]){
            if(!valid(graph, dp, n, set)){
                return false;
            }
        }
        set.erase(neigh);
        dp[neigh] = true;
        return true;
    }
};