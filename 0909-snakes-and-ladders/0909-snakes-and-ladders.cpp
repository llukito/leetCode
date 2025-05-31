class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int,int>> q;
        q.push({1, 0});
         vector<bool> visited(n * n + 1, false);
         visited[0] = true;
        while(!q.empty()){
            int curr = q.front().first; int steps = q.front().second; q.pop();
            if(curr == n*n){
                return steps;
            }
            for(int i=curr+1; i<=min(curr+6, n*n); i++){
                 int r = n - 1 - ((i - 1) / n);
                int c = ( (i - 1) % n );

                if ( (( (i - 1) / n ) % 2 ) == 1 ) {
                    c = n - 1 - c;
                }
                if(!visited[i]){
                    visited[i] = true;
                    if (board[r][c] == -1) {
                    q.push({ i, steps + 1 });
                } else {
                    q.push({ board[r][c], steps + 1 });
                }
                }
            }
        }
        return -1;
    }
};