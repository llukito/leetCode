class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int,int>>> map;
        for(vector<int> v : edges){
            map[v[0]].push_back({v[1], v[2]});
            map[v[1]].push_back({v[0], v[2]});
        }
        int temp = INT_MAX;
        int result = -1;
        for(int i=0; i<n; i++){
            int neighbours = dij(map, distanceThreshold, i, n);
            cout<<i<<" "<<neighbours<<endl;
            if(neighbours <= temp){
                temp = neighbours;
                result = i;
            }
        }
        return result;
    }

    int dij(unordered_map<int, vector<pair<int,int>>>& map, int& thr, int start, int& n){
        int count = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});
        vector<int> dist(n, INT_MAX);
        while(!pq.empty()){
            pair<int,int> pai = pq.top();
            int val = pai.second; int len = pai.first; pq.pop();
            if(len > thr)continue;
            if(len > dist[val])continue;
            for(pair<int,int> p : map[val]){
                if(len + p.second < dist[p.first] && len + p.second <= thr){
                    dist[p.first] = len+p.second;
                    pq.push({dist[p.first], p.first});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != start && dist[i] <= thr) count++;
        }
        return count;
    }
};