class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long res = 0;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int,int>>>, greater<>> pq;
        for(int n : workerTimes){
            pq.push({n, {n, 1}});
        }
        while(mountainHeight != 0){
            auto [cost, inner] = pq.top(); pq.pop();
            auto [turn, dec] = inner;
            mountainHeight-= 1;
            res = cost;
            if(mountainHeight <= 0)break;
            pq.push({cost + 1ll*turn*(dec + 1), {turn, dec+1}});
        }
        return res;
    }
};
