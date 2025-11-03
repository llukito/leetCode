class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int inRow = 0; int minTime = INT_MAX; char prev = '-';
        int res = 0;
        for(int i=0; i<colors.size(); i++){
            if(prev == colors[i]){
                inRow++;
                minTime = min(minTime, neededTime[i]);
            } else {
                if(inRow > 1){
                    res+= minTime;
                }
                prev = colors[i];
                inRow = 1;
                minTime = neededTime[i];
            }
        }
        if(inRow > 1){
            res+= minTime;
        }
        return res;
    }
};