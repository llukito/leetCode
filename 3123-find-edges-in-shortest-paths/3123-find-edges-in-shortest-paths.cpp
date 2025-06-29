class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> dist1;
        fill(dist1, n, edges, 0);
        unordered_map<int, int> dist2;
        fill(dist2, n, edges, n-1);
        vector<bool> res(edges.size(), false);
        int idx = 0;
        for(vector<int> edge : edges){
            if(dist1[edge[0]] + edge[2] + dist2[edge[1]] == dist1[n-1] || dist1[edge[1]] + edge[2] + dist2[edge[0]] == dist1[n-1]){
                res[idx++] =true;
            } else {
                res[idx++] =false;
            }
        }
        return res;
    }

    void fill(unordered_map<int, int>& dist1, int n, vector<vector<int>>& edges, int start){
        unordered_map<int,vector<pair<int,int>> > graph;
        for(vector<int> vect : edges){
            graph[vect[0]].push_back({vect[1], vect[2]});
            graph[vect[1]].push_back({vect[0], vect[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});
        while(!pq.empty()){
            int len = pq.top().first; int node = pq.top().second; pq.pop();
            if(dist1.count(node)){
                if(dist1[node] < len)continue;
            }
            dist1[node] = len;
            for(pair<int,int> pr : graph[node]){
                if(!dist1.count(pr.first)){
                    dist1[pr.first] = len+pr.second;
                    pq.push({len+pr.second, pr.first});
                } else if(dist1[pr.first] > len+pr.second){
                    dist1[pr.first] = len+pr.second;
                    pq.push({len+pr.second, pr.first});
                }
            }
        }
    }
};