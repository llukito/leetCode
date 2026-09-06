class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        for(int i = 0; i < n; i++){
            res[0][i] = '.';
        }
        for(int i = 0; i < m; i++){
            res[i][n-1] = '.';
        }
        return res;
    }
};
