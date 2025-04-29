class Solution {
public:
    int numberOfMatches(int n) {
        int games = 0;
        while(n!=1){
            if(n%2==0){
                games+=n/2;
                n=n/2;
            } else {
                games+=n/2;
                n=n/2 +1;
            }
        }
        return games;
    }
};