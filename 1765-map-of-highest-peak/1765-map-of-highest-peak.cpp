class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        unordered_set<int> set;
        queue<pair<int,int>> q;
        for(int r=0; r<isWater.size(); r++){
            for(int c=0; c<isWater[0].size(); c++){
                if(isWater[r][c] == 1){
                    q.push({r,c});   
                }
                isWater[r][c] = -1;
            }
        }
        int val = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int r = q.front().first; int c = q.front().second; q.pop();
                if(r<0 || r>=isWater.size() || c<0 || c>=isWater[0].size())continue;
                if(isWater[r][c] != -1)continue;
                if(set.count(r*isWater[0].size()+c))continue;
                set.insert(r*isWater[0].size()+c);
                isWater[r][c] = val;
                q.push({r+1,c});
                q.push({r-1,c});
                q.push({r,c+1});
                q.push({r,c-1});
            }
            val++;
        }
        return isWater;
    }
};