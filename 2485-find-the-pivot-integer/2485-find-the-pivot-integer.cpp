class Solution {
public:
    int pivotInteger(int n) {
        int m = (n*n+n)/2;
        int num = sqrt(m);
        return num*num == m?  num : -1;
    }
};