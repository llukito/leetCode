class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int dir = 0; // 0 - north, 1 - east, 2 - south, 3 - west
        int res = 0;
        int curr = 0;
        unordered_set<long long> set;
        for(auto& t : obstacles){
            set.insert(1ll*t[0]*INT_MAX+t[1]);
        }
        for(int i = 0; i < commands.size(); i++){
            int currCommand = commands[i];
            if(currCommand == -2){
                dir = (4+dir-1)%4;
            } else if(currCommand == -1){
                dir = (dir+1)%4;
            } else {
                for(int j = 1; j <= currCommand; j++){
                    if(dir == 0){
                        y++;
                        if(set.count(1ll*x*INT_MAX+y)){
                            y--;
                            break;
                        }
                    } else if(dir == 2){
                        y--;
                        if(set.count(1ll*x*INT_MAX+y)){
                            y++;
                            break;
                        }
                    } else if(dir == 1){
                        x++;
                        if(set.count(1ll*x*INT_MAX+y)){
                            x--;
                            break;
                        }
                    } else {
                        x--;
                        if(set.count(1ll*x*INT_MAX+y)){
                            x++;
                            break;
                        }
                    }
                    curr = 1ll*x*x + 1ll*y*y;
                    res = max(res, curr);
                }
            }
        }
        return res;
    }
};
