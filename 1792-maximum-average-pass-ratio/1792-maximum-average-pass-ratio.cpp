class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, vector<int>>> q;
        for(vector<int> v : classes){
            double curr = static_cast<double>(v[0])/(v[1]);
            double nw = static_cast<double>(v[0]+1)/(v[1]+1);
            q.push({nw-curr, v});
        }
        for(int i=0; i<extraStudents; i++){
            auto p = q.top(); q.pop();
            vector<int> v = p.second;
            v[0]+=1; v[1]+=1;
            double curr = static_cast<double>(v[0])/(v[1]);
            double nw = static_cast<double>(v[0]+1)/(v[1]+1);
            q.push({nw-curr, v});
        }
        double all = 0;
        while(!q.empty()){
            vector<int> v = q.top().second; q.pop();
            all+=static_cast<double>(v[0])/(v[1]);
        }
        return double(all)/classes.size();
    }
};