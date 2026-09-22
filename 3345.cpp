class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n){
            if(mult(n) % t == 0)return n;
            n++;
        }
        return -1;
    }

    int mult(int n){
        int m = 1;
        while(n!=0){
            m*=(n%10);
            n/=10;
        }
        return m;
    }
};
