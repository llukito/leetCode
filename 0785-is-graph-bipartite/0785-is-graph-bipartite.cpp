class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(visited[i]==-1){
                bool b1 = !dfs(graph, visited, 0, i);
                if(b1)return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int color, int node){
        visited[node] = color;
        for(int nei : graph[node]){
            if(visited[nei] == -1){
                int nextColor = color == 0 ? 1 : 0;
                if(!dfs(graph, visited, nextColor, nei))return false;
            } else if( visited[nei] == color ){
                return false;
            }
        }
        return true;
    }
};