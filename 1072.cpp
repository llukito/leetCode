class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;

        for(int r = 0; r < matrix.size(); r++){
                string miss1 = "";
                string miss2 = "";
            for(int c = 0; c < matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                    miss1 += to_string(c) + "|";
                } else {
                    miss2 += to_string(c) + "|";
                }
            }
            mp[miss1]++;
            mp[miss2]++;
        }

        int res = 0;
        for(auto& en : mp){
            res = max(res, en.second);
        }
        return res;
    }
};
