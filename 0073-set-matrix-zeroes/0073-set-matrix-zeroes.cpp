class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()<2){
            if(find(matrix[0].begin(), matrix[0].end(), 0) != matrix[0].end()){
                for(int i=0; i<matrix[0].size(); i++){
                    matrix[0][i] = 0;
                }
            }
        } else if(matrix[0].size() < 2){
            for(int i=0; i<matrix.size(); i++){
                if(matrix[i][0] == 0){
                    for(int j=0; j<matrix.size(); j++){
                        matrix[j][0] = 0;
                    }
                    break;
                }
            }
        } else {
            for(int r = 1; r<matrix.size(); r++){
                for(int c = 1; c<matrix[0].size(); c++){
                    if(matrix[r][c] == 0){
                        matrix[0][c] = 0;
                        matrix[r][0] = 0;
                    }
                }
            }
            for(int c=1; c<matrix[0].size(); c++){
                if(matrix[0][c] == 0){
                    for(int r = 1; r<matrix.size(); r++){
                        matrix[r][c] = 0;
                    }
                }
            }

            for(int r=1; r<matrix.size(); r++){
                if(matrix[r][0] == 0){
                    for(int c = 1; c<matrix[0].size(); c++){
                        matrix[r][c] = 0;
                    }
                }
            }

            if(matrix[0][0] == 0){
                for(int r=1; r<matrix.size(); r++){
                    matrix[r][0] = 0;
                }
                for(int c=1; c<matrix[0].size(); c++){
                    matrix[0][c] = 0;
                }
            }
        }
    }
};