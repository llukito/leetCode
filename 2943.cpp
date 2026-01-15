class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int hmax = 0, vmax = 0;

        int curr = hBars[0];
        int c = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i]-1==curr){
                c++;
            } else {
                hmax = max(c+1, hmax);
                c = 1;
            }
            curr = hBars[i];
        }
        hmax = max(c+1, hmax);

        curr = vBars[0];
        c = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i]-1==curr){
                c++;
            } else {
                vmax = max(c+1, vmax);
                c = 1;
            }
            curr = vBars[i];
        }
        vmax = max(c+1, vmax);

        return pow(min(vmax, hmax), 2);
    }
};
