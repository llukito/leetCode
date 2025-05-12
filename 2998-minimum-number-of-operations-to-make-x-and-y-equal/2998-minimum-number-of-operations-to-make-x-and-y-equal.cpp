class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x < y)return y-x;
        int U = x-y;
        queue<pair<int,int>> q;
        q.push({x,0});
        unordered_set<int> set;
        while(!q.empty()){
            pair<int,int> pr = q.front(); q.pop();
            int num = pr.first;
            if(num == y){
                return min(U, pr.second);
            }
            if(num%11 == 0 && !set.count(num/11)){
                set.insert(num/11);
                q.push({num/11, pr.second+1});
            }
            if(num%5 == 0 && !set.count(num/5)){
                set.insert(num/5);
                q.push({num/5, pr.second+1});
            }
            if(!set.count(num+1)){
                set.insert(num+1);
                q.push({num+1, pr.second+1});
            }
            if(!set.count(num-1)){
                set.insert(num-1);
                q.push({num-1, pr.second+1});
            }
        }
        return -1;
    }
};