class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==1){
            vector<int>& vec = matrix[0];
            return find(vec.begin(), vec.end(), target)!=vec.end();
        }
        for(int i=0; i<matrix.size()-1; i++){
            if(matrix[i][0]==target || matrix[i+1][0]==target)return true;
            if(matrix[i][0]<target && matrix[i+1][0]>target){
                vector<int>& vec = matrix[i];
                return find(vec.begin(), vec.end(), target)!=vec.end();
            }
        }
        vector<int>& vec = matrix.back();
        return find(vec.begin(), vec.end(), target)!=vec.end();
    }
};