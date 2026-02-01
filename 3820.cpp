class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        // store graph in map
        unordered_map<int, vector<int>> graph;
        for(auto& t : edges){
            graph[t[0]].push_back(t[1]);
            graph[t[1]].push_back(t[0]);
        }
        vector<vector<int>> dist(3, vector<int>(n, -1));
        dfs(x, 0, dist, graph, 0);
        dfs(y, 1, dist, graph, 0);
        dfs(z, 2, dist, graph, 0);
        int res = 0;
        for(int i = 0; i < n; i++){
            vector<int> vect;
            vect.push_back(dist[0][i]);
            vect.push_back(dist[1][i]);
            vect.push_back(dist[2][i]);
            sort(vect.begin(), vect.end());
            if(1ll*vect[0]*vect[0] + 1ll*vect[1]*vect[1] == 1ll*vect[2]*vect[2])res++;
        }
        return res;
    }

    void dfs(int node, int a, auto& dist, auto& graph, int curr){
        if(dist[a][node]!=-1)return;
        dist[a][node] = curr;
        for(int n : graph[node]){
            dfs(n, a, dist, graph, curr+1);
        }
    }
};
