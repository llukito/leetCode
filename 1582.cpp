class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_set<int> rows, cols;
        for(int r = 0; r < mat.size(); r++){
            int n =0;
            for(int c = 0; c < mat[0].size(); c++){
                if(mat[r][c]!=0){
                    n++;
                }
            }
            if(n==1)rows.insert(r);
        }
        for(int c = 0; c < mat[0].size(); c++){
            int n =0;
            for(int r = 0; r < mat.size(); r++){
                if(mat[r][c]!=0){
                    n++;
                }
            }
            if(n==1)cols.insert(c);
        }
        int res = 0;
       for(int r = 0; r < mat.size(); r++){
            for(int c = 0; c < mat[0].size(); c++){
                if(mat[r][c]!=0 && rows.count(r) && cols.count(c)){
                    res++;
                }
            }
            
        }
        return res;
    }
};