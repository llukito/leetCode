class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        for(auto& entry : queries){
            for(int r = entry[0]; r <= entry[2]; r++){
                result[r][entry[1]]++;
                if(entry[3]+1 < n)
                result[r][entry[3]+1]--;
            }
        }
        for(int r = 0; r < n; r++){
            for(int c = 1; c < n; c++){
                result[r][c]+=result[r][c-1];
            }
        }
        return result;
    }
};