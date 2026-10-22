class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());
        int cs = 0;
        int inRow = 0;
        for(int n : cost){
            inRow++;
            if(inRow != 3){
                cs+=n;
            } else {
                inRow = 0;
            }
        }
        return cs;
    }
};
