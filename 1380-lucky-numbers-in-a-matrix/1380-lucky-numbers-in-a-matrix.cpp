class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), INT_MAX); vector<int> cols(matrix[0].size(), INT_MIN);
        for(int r = 0; r<matrix.size(); r++){
            for(int c = 0; c<matrix[0].size(); c++){
                rows[r] = min(rows[r], matrix[r][c]);
                cols[c] = max(cols[c], matrix[r][c]);
            }
        }
        vector<int> res;
         for(int r = 0; r<matrix.size(); r++){
            for(int c = 0; c<matrix[0].size(); c++){
                if(matrix[r][c] == rows[r] && rows[r] == cols[c]){
                    res.push_back(rows[r]);
                }
            }
        }
        return res;
    }
};