class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> vect(10, 0);
        while(n!=0){
            vect[n%10]++;
            n/=10;
        }
        int m = 0;
        for(int i = 0 ; i < 10; i++){
            m+=vect[i]*i;
        }
        return m;
    }
};
