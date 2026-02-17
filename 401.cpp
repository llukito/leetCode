class Solution {
public:
const int maxLedHour = 3;
const int maxLedMin = 5;
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> watchHours = {8,4,2,1};
        vector<int> watchMinutes = {32, 16, 8, 4, 2, 1};
        if(turnedOn > 8)return {};
        vector<pair<int,int>> variants;
        for(int i = 0; i < turnedOn/2 + 1; i++){
            variants.push_back({i, turnedOn-i});
            if(i != turnedOn-i)variants.push_back({turnedOn-i, i});
        }
        vector<string> res;
        for(auto& p : variants){
            int ch = p.first; int cm = p.second;
            if(ch > maxLedHour || cm > maxLedMin)continue;
            vector<int> hours; vector<int> minutes;
            fill(hours, watchHours, ch, 0, 0);
            fill(minutes, watchMinutes, cm, 0, 0);
            for(int h : hours){
                for(int m : minutes){
                    if(h > 11 || m > 59)continue;
                    string curr = to_string(h);
                    curr+=":";
                    if(m < 10){
                        curr+="0";
                    }
                    curr+= to_string(m);
                    res.push_back(curr);
                }
            }
        }
        return res;
    }

    void fill(auto& res, auto& vect, int n, int idx, int sum){
        if(n == 0){
            res.push_back(sum);
            return;
        }
        if(idx >= vect.size())return;
        fill(res, vect, n-1, idx+1, sum+vect[idx]);
        fill(res, vect, n, idx+1, sum);
    }
};
