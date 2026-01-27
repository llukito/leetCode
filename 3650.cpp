class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> graph;
        unordered_map<int, vector<pair<int,int>>> incoming;
        for(auto& v : edges){
            graph[v[0]].push_back({v[1], v[2]});
            incoming[v[1]].push_back({v[0], 2*v[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        unordered_map<int, int> dist;
        dist[0] = 0;
        vector<bool> used(n, false);
        q.push({0, 0});
        while(!q.empty()){
            auto top = q.top(); q.pop();
            int sz = top.first; int node = top.second;
            if(node == n-1)break;
            for(auto& p : graph[node]){
                if(!dist.count(p.first) || dist[p.first] > sz + p.second){
                    dist[p.first] = sz+p.second;
                    q.push({dist[p.first], p.first});
                }
            }

            if(!used[node]){
                used[node] = true;
                for(auto& p : incoming[node]){
                    if(!dist.count(p.first) || dist[p.first] > sz + p.second){
                        dist[p.first] = sz+p.second;
                        q.push({dist[p.first], p.first});
                    }
                }
            }
        }
        return dist.count(n-1) ? dist[n-1] : -1;
    }
};
