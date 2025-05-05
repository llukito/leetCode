class Solution {
public:
    int arrangeCoins(int n) {
        int dec = 1;
        int res = 0;
        n--;
        while(n>=0){
            dec++;
            res++;
            n-=dec;
        }
        return res;
    }
};