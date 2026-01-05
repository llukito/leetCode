class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int numOfNeg = 0;
        long long sumAll = 0;
        int min_ = INT_MAX;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                if(matrix[r][c] < 0){
                    numOfNeg++;
                }
                sumAll+=abs(matrix[r][c]);
                min_ = min(min_, abs(matrix[r][c]));
            }
        }
        if(numOfNeg%2 == 0)return sumAll;
        return sumAll - 2*min_;
    }
};
