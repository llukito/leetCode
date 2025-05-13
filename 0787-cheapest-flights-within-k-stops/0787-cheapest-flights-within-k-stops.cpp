class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Priority queue for (cost, city, stops_left) where cost is the current cost, city is the current city, and stops_left is the remaining number of stops
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        q.push(make_tuple(0, src, k)); // Initial state: cost = 0, src city, k stops left
        
        // dp[city][stops_left] = minimum cost to reach `city` with `stops_left` remaining stops
        unordered_map<int, unordered_map<int, int>> dp;
        
        // Add initial state to dp (src, k)
        dp[src][k] = 0;
        
        while (!q.empty()) {
            tuple<int, int, int> t = q.top(); q.pop();
            int city = get<1>(t);
            int cost = get<0>(t);
            int stops_left = get<2>(t);
            
            // If we reach the destination, return the cost
            if (city == dst) {
                return cost;
            }
            
            // If there are still stops remaining, explore the next cities
            if (stops_left >= 0) {
                for (const auto& flight : flights) {
                    int from = flight[0], to = flight[1], price = flight[2];
                    
                    // If we're at the `from` city, check if moving to `to` city with 1 fewer stop is cheaper
                    if (from == city) {
                        int new_cost = cost + price;
                        
                        // If this new path to `to` city with `stops_left - 1` stops is cheaper, update and push to the queue
                        if (dp[to].find(stops_left - 1) == dp[to].end() || dp[to][stops_left - 1] > new_cost) {
                            dp[to][stops_left - 1] = new_cost;
                            q.push(make_tuple(new_cost, to, stops_left - 1));
                        }
                    }
                }
            }
        }
        
        // If no valid path is found, return -1
        return -1;
    }
};
