class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x < y) {
            return y - x;
        }
        int time = x - y;
        int U = time+x;
        queue<pair<int,int>> q;
        q.push({0, x});
        while(!q.empty()){
            int curr = q.front().first;
            int val = q.front().second;
            if(val >= U)break;
            q.pop();
            if(val == y){
                time = min(curr, time);
                break;
            }
            if(val%11 == 0 && curr+1 < time){
                q.push({curr+1, val/11});
            }
            if(val%5 == 0 && curr+1 < time){
                q.push({curr+1, val/5});
            }
            if(curr+1<time){
                q.push({curr+1, val+1});
                q.push({curr+1, val-1});
            }
        }
        return time;
    }
};