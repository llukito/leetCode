class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++){
            if(nonZero(i) && nonZero(n-i)){
                return {i, n-i};
            }
        }
        return {-1,-1}; // will not happen
    }

    bool nonZero(int i){
        while(i!=0){
            if(i%10 == 0)return false;
            i/=10;
        }
        return true;
    }
};