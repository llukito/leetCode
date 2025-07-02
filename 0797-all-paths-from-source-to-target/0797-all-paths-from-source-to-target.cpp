class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> curr;
        curr.push_back(0);
        fill(res, curr, graph, 0);
        return res;
    }

    void fill(vector<vector<int>>& res, vector<int>& curr,vector<vector<int>>& graph, int node){
        if(node == graph.size()-1){
            res.push_back(curr);
            return;
        }
        for(int nei : graph[node]){
            curr.push_back(nei);
            fill(res, curr, graph, nei);
            curr.pop_back();
        }
    }
};