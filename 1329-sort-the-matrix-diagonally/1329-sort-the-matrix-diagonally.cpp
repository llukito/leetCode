class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for(int c = 0; c < mat[0].size(); c++){
            vector<int> vect;
            int r = 0;
            int col = c;
            while(col<mat[0].size() && r<mat.size()){
                vect.push_back(mat[r][col]);
                r++;
                col++;
            }
            sort(vect.begin(), vect.end());
            int indx = 0;
            r = 0;
            col = c;
             while(col<mat[0].size() && r<mat.size()){
                res[r][col] = vect[indx++];
                r++;
                col++;
            }
        }
        for(int row = 1; row<mat.size(); row++){
            vector<int> vect;
            int r = row;
            int col = 0;
            while(col<mat[0].size() && r<mat.size()){
                vect.push_back(mat[r][col]);
                r++;
                col++;
            }
            sort(vect.begin(), vect.end());
            int indx = 0;
            r = row;
            col = 0;
             while(col<mat[0].size() && r<mat.size()){
                res[r][col] = vect[indx++];
                r++;
                col++;
            }
        }
        return res;
    }
};