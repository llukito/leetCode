class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);
        vector<int> minDist(n, INT_MAX);

        priority_queue<pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>> pq;

        minDist[0] = 0;
        pq.push({0, 0});

        int result = 0;

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (inMST[u]) continue;  
            inMST[u] = true;
            result += cost;

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int w = abs(points[u][0]-points[v][0]) 
                          + abs(points[u][1]-points[v][1]);

                    if (w < minDist[v]) {
                        minDist[v] = w;
                        pq.push({w, v});
                    }
                }
            }
        }
        return result;
    }
};