class Solution {
public:
struct compare{
    bool operator()(const tuple<int,int,int>& t1,const tuple<int,int,int>& t2){
        return get<1>(t1) > get<1>(t2);
    }
};
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, compare> pr;
        vector<int> remembered(n, INT_MAX);
        pr.push(make_tuple(0,passingFees[0],0));
        while(!pr.empty()){
            int numb = get<0>(pr.top());
            int len = get<1>(pr.top());
            int time = get<2>(pr.top());
            pr.pop();
            if(numb == n-1 && time<=maxTime){
                return len;
            }
            for(pair<int, int> myPair : graph[numb]){
                int dest = myPair.first; int t = myPair.second;
                if(len+passingFees[dest] < remembered[dest] && time+t<=maxTime){
                    remembered[dest] = len+passingFees[dest];
                    pr.push(make_tuple(dest,remembered[dest], time+t));
                }
            }
        }
        return -1;
    }
};