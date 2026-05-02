class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> vect(matrix.size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix.size(); j++){
                if(matrix[i][j] == 1){
                    vect[i]++;
                    vect[j]++;
                }
            }
        }
        return vect;
    }
};
