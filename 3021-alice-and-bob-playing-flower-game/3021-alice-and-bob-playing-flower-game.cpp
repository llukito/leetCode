class Solution {
public:
    long long flowerGame(int n, int m) {
        int odds1 = ((n+1)/2);
        int evens1 = n-odds1;
        int odds2 = ((m+1)/2);
        int evens2 = m-odds2;
        return 1LL*odds1*evens2 + 1LL*odds2*evens1;
    }
};