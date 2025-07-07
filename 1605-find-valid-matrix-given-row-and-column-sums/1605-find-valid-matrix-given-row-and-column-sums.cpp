class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> vect(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int r = 0; r<rowSum.size(); r++){
            for(int c =0 ; c<colSum.size(); c++){
                vect[r][c] = min(rowSum[r],colSum[c]);
                colSum[c]-=vect[r][c];
                rowSum[r]-=vect[r][c];
            }
        }
        return vect;
    }
};