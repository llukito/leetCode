class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size(), false);
        int res = 0;
        for(int f : fruits){
            if(!possible(f, used, baskets)){
                res++;
            }
        }
        return res;
    }

    bool possible(int f, vector<bool>& used, vector<int>& baskets){
        for(int i=0; i<baskets.size(); i++){
            if(baskets[i] >= f && !used[i]){
                used[i] = true;
                return true;
            }
        }
        return false;
    }
};