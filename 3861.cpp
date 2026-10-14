class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int min_ = INT_MAX;
        int res = -1;
        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] >= itemSize && capacity[i] < min_){
                min_ =  capacity[i];
                res = i;
            }
        }
        return res;
    }
};
