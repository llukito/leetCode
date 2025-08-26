class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                int curr = i*grid[0].size()+j;
                if(i+1<grid.size()){
                    graph[curr].push_back({(i+1)*grid[0].size()+j, grid[i+1][j]});
                }
                if(i-1>=0){
                    graph[curr].push_back({(i-1)*grid[0].size()+j, grid[i-1][j]});
                }
                if(j+1<grid[0].size()){
                    graph[curr].push_back({(i)*grid[0].size()+j+1, grid[i][j+1]});
                }
                if(j-1>=0){
                    graph[curr].push_back({(i)*grid[0].size()+j-1, grid[i][j-1]});
                }
            }
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        unordered_map<int,int> dist;
        while(!pq.empty()){
            int dis = pq.top().first; int node = pq.top().second; pq.pop();
            if(dist.count(node)){
                if(dist[node]<dis)continue;
            }
            dist[node] = dis;
            for(auto& p : graph[node]){
                if(!dist.count(p.first) || dist[p.first]>dis+p.second){
                    pq.push({dis+p.second, p.first});
                }
            }
        }
        return dist[grid.size()*grid[0].size()-1];
    }
};