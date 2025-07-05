class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {src, 0}});
        unordered_map<int, unordered_map<int,int>> dist;
        dist[src][0] = 0;
        while(!pq.empty()){
            int node = pq.top().second.first; int len = pq.top().first; int total = pq.top().second.second; pq.pop();
            if(total >k)continue;
            if(dist.count(node) && dist[node].count(total) && dist[node][total] < len)continue;
            dist[node][total] = len;
            if(node == dst)return len;
            for(auto& vect : flights){
                int from = vect[0]; int to = vect[1]; int cost = vect[2];
                if(from == node){
                    if(!dist.count(vect[1]) || !dist[vect[1]].count(total+1)){
                        pq.push({len + vect[2], {vect[1], total + 1}});
                    } else if(dist[vect[1]][total+1] > len+vect[2]){
                        pq.push({len + vect[2], {vect[1], total + 1}});
                    }
                }
            }
        }
        return -1;
    }
};