class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for(int i=0; i<=limit; i++){
            for(int j=0; j<=limit; j++){
                for(int c=0; c<=limit; c++){
                    if(i+j+c == n)res++;
                }
            }
        }
        return res;
    }

};