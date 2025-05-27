class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vect(n, vector<int>(n,0));
        int num = 1;
        fill(vect, num, 0, n-1);
        return vect;
    }

    void fill(vector<vector<int>>& vect, int& num, int s, int e){
        if(s > e)return;
        for(int i = s; i<=e; i++){
            vect[s][i] = num;
            num++;
        }
        for(int i = s+1; i<=e; i++){
            vect[i][e] = num;
            num++;
        }
        for(int i = e-1; i>=s; i--){
            vect[e][i] = num;
            num++;
        }
        for(int i = e-1; i>=s+1; i--){
            vect[i][s] = num;
            num++;
        }
        fill(vect, num, s+1, e-1);
    }
};