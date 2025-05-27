class Solution {
public:
    int differenceOfSums(int n, int m) {
        int val1 = 0;
        int val2 = 0;
        for(int i=1; i<=n; i++){
            if(i%m!=0){
                val1+=i;
            } else {
                val2+=i;
            }
        }
        return val1-val2;
    }
};