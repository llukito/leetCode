class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c){
        if(dp[r][c]!=-1)return dp[r][c];
        int n1=0; int n2=0; int n3=0; int n4=0;
        if(r+1<matrix.size() && matrix[r][c]<matrix[r+1][c]){
            n1 = dfs(matrix,r+1,c);
        }
        if(r-1>=0 && matrix[r][c]<matrix[r-1][c] ){
            n2 = dfs(matrix,r-1,c);
        }
        if(c+1<matrix[0].size() && matrix[r][c]<matrix[r][c+1]){
            n3 = dfs(matrix,r,c+1);
        }
        if(c-1>=0 &&  matrix[r][c]<matrix[r][c-1]){
            n4 = dfs(matrix,r,c-1);
        }
        int res = 1 + max({n1,n2,n3,n4});
        return dp[r][c] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n,-1));
        int longest = 0;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                longest = max(longest, dfs(matrix,r,c));
            }
        }
        return longest;
    }
};