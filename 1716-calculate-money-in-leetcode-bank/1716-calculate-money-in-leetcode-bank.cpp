class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int ind = 1;
        int start = 1;
        int it = 0;
        for(int i=1; i<=n; i++){
            sum+=start++;
            it++;
            if(it==7){
                it=0;
                start=++ind;
            }
        }
        return sum;
    }
};