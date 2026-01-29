class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> graph;
        int n = original.size();
        for(int i = 0; i < n; i++){
            graph[original[i]].push_back({changed[i], cost[i]});
        }
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        for(char ch = 'a'; ch <= 'z'; ch++){
            deikstra(dist, graph, ch);
        }
        long long res = 0;
        for(int i = 0; i < source.size(); i++){
            if(source[i] != target[i]){
                long long curr = dist[source[i]-'a'][target[i]-'a'];
                if(curr == LLONG_MAX)return -1;
                res+= curr;
            }
        }
        return res;
    }

    void deikstra(auto& dist, auto& graph, char ch){
        priority_queue<pair<long long, char>, vector<pair<long long,char>>, greater<pair<long long,char>>> q;
        q.push({0, ch});
        while(!q.empty()){
            auto top = q.top(); q.pop();
            long long sz = top.first; char node = top.second;
            for(auto& p : graph[node]){
                if(dist[ch-'a'][p.first-'a'] > sz + p.second){
                    dist[ch-'a'][p.first-'a'] = sz+p.second;
                    q.push({sz+p.second, p.first});
                }
            }
        }
    }
};
