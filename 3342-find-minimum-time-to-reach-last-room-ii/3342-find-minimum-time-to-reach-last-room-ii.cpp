class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int r = moveTime.size();
        int c = moveTime[0].size();
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        pq.push(make_tuple(0,0,0,0));
        vector<vector<int>> visited(r, vector<int>(c, INT_MAX));
        visited[0][0] = 0;
        vector<vector<int>> directions{{0, 1}, {1,0}, {-1,0}, {0, -1}};
        while(!pq.empty()){
            auto t = pq.top(); pq.pop();
            int time = get<0>(t); int x = get<1>(t); int y = get<2>(t); int steps = get<3>(t);
            if(x == r-1 && y == c-1){
                return time;
            }
            for(vector<int> vect : directions){
                int nX = x + vect[0];
                int nY = y + vect[1];
                if(nX >=0 && nY >=0 && nX<r && nY < c){
                    int add = steps%2==0 ? 1 : 2;
                    int newTime = max(time + add, moveTime[nX][nY]+add);
                    if(newTime < visited[nX][nY]){
                        visited[nX][nY] = newTime;
                        pq.push(make_tuple(newTime, nX, nY, steps+1));
                    }
                }
            }
        }
        return -1; // should not reach this
    }
};
