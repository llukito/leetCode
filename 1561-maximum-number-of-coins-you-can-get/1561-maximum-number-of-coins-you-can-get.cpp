class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0;
        int takes = piles.size()/3;
        for(int i=piles.size()-2; i>=0 && takes>0; i-=2){
            res+=piles[i];
            takes--;
        }
        return res;
    }
}; 