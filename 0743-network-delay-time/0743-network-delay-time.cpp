class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for(vector<int> vect : times){
            graph[vect[0]].push_back({vect[1], vect[2]});
        }
        vector<int> remembered(n+1, INT_MAX);
        priority_queue<pair<int,int>> pq;
        pq.push({k, 0});
        while(!pq.empty()){
            int node = pq.top().first;
            int time = pq.top().second; pq.pop();
            for(pair<int,int> pr : graph[node]){
                int newNode = pr.first; int newTime = pr.second;
                if(remembered[newNode]>time+newTime){
                    remembered[newNode] = time+newTime;
                    pq.push({newNode, remembered[newNode]});
                }
            }
        }
        int time = INT_MIN;
        for(int i=1; i<remembered.size(); i++){
            if(i==k)continue;
            int num = remembered[i];
            if(num == INT_MAX)return -1;
            time = max(num, time);
        }
        return time;
    }
};