class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        k%=mat[0].size();
        for(int r = 0; r < mat.size(); r++){
            for(int c = 0; c < mat[0].size(); c++){
                if(r%2 == 0){
                    if(mat[r][c] != mat[r][(mat[0].size()+c-k)%mat[0].size()])return false;
                } else {
                    if(mat[r][c] != mat[r][(mat[0].size()+c+k)%mat[0].size()])return false;
                }
            }
        }
        return true;
    }
};
