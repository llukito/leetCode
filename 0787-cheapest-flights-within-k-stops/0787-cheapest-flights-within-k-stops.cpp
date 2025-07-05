class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights)
            graph[f[0]].emplace_back(f[1], f[2]);

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top(); pq.pop();
            if (node == dst) return cost;
            if (stops == k) continue;

            for (auto& [nei, price] : graph[node]) {
                if (dist[nei][stops + 1] > cost + price) {
                    dist[nei][stops + 1] = cost + price;
                    pq.emplace(cost + price, nei, stops + 1);
                }
            }
        }
        return -1;
    }
};
