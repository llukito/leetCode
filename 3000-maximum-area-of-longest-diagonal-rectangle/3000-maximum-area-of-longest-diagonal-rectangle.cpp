class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        int diag = 0;
        for(vector<int> vect : dimensions){
            int n = vect[0]; int m = vect[1];
            int diagInPower = n*n + m*m;
            if(diagInPower > diag){
                diag = diagInPower;
                area = n*m;
            } else if(diagInPower == diag && m*n > area){
                area = m*n;
            }
        }
        return area;
    }
};