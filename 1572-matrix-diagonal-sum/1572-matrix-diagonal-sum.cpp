class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for(int i=0; i<mat.size(); i++){
            res+=mat[i][i];
        }
        int r = mat.size()-1;
        for(int i=0; i<mat[0].size(); i++){
            if(r == i){
                r--;
                continue;
            }
            res+=mat[r--][i];
        }
        return res;
    }
};