class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        int prev = colors[0];
        for(int i = colors.size()-1; i >=0; i--){
            if(colors[i] != prev){
                res = max(res, i);
                break;
            }
        }
        prev = colors[colors.size()-1];
        for(int i = 0; i < colors.size(); i++){
            if(colors[i] != prev){
                res = max(res, (int)colors.size()-i-1);
                break;
            }
        }
        return res;
    }
};
