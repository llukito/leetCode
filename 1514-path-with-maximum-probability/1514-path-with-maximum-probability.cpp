class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double>>> graph;
        for(int i=0; i<edges.size(); i++){
            vector<int> vect = edges[i];
            graph[vect[0]].push_back({vect[1], succProb[i]});
            graph[vect[1]].push_back({vect[0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        unordered_map<int,double> dist;
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()){
            int node = pq.top().second; double prob = pq.top().first; pq.pop();
            // if(node == end_node){
            //     dist[node] = max(dist[node], prob);
            //     continue;
            // }
            if(dist.count(node)){
                if(dist[node]>prob)continue;
            }
            dist[node] = prob;
            for(pair<int,double> pr : graph[node]){
                if(!dist.count(pr.first) || dist[pr.first] < prob*pr.second){
                    dist[pr.first] = prob*pr.second;
                    pq.push({prob*pr.second, pr.first});
                }
            }
        }
        return dist[end_node];
    }
};