class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x < y) {
            return y - x;
        }
        int time = x - y;
        queue<pair<int,int>> q;
        q.push({0, x});
        unordered_set<int> set;
        while(!q.empty()){
            int curr = q.front().first;
            int val = q.front().second;
            q.pop();
            if(val == y){
                time = min(curr, time);
                break;
            }
            if(val%11 == 0 && curr+1 < time && !set.count(val/11)){
                q.push({curr+1, val/11});
                set.insert(val/11);
            }
            if(val%5 == 0 && curr+1 < time && !set.count(val/5)){
                q.push({curr+1, val/5});
                set.insert(val/5);
            }
            if(curr+1<time && !set.count(val+1)){
                q.push({curr+1, val+1});
                set.insert(val+1);
            }
            if(curr+1<time && !set.count(val-1)){
                q.push({curr+1, val-1});
                set.insert(val-1);
            }
        }
        return time;
    }
};