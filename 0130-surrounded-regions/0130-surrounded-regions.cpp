class Solution {
public:
    void solve(vector<vector<char>>& board) {
        unordered_set<int> set;
        for(int r = 0; r<board.size(); r++){
            for(int c = 0; c<board[0].size(); c++){
                if(board[r][c] == 'O' &&  !set.count(r*board.size()+c)){
                    set.insert(r*board.size()+c);
                    unordered_set<int> current;
                    current.insert(r*board[0].size()+c);
                    bool b = true;
                    if(r==board.size()-1 || c== board[0].size()-1 || r==0 || c==0){
                        b = false;
                    }
                    dfs(board, r, c, set, current, b);
                    if(b){
                        cout<<"d"<<endl;
                        for(int num : current){
                            int rr = num/board[0].size();
                            int cc = num - rr*board[0].size();
                            board[rr][cc] = 'X';
                        }
                    }
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c, unordered_set<int>& set, unordered_set<int>& current, bool& b){
        if(r+1<board.size() && board[r+1][c] == 'O' && !set.count((r+1)*board[0].size()+c)){
            set.insert((r+1)*board[0].size()+c);
            current.insert((r+1)*board[0].size()+c);
            if(r+1 ==board.size()-1){
                b = false;
            }
            dfs(board, r+1, c, set, current, b);
        }
         if(r-1>=0 && board[r-1][c] == 'O'&& !set.count((r-1)*board[0].size()+c)){
            set.insert((r-1)*board[0].size()+c);
            current.insert((r-1)*board[0].size()+c);
            if(r-1 ==0){
                b = false;
            }
            dfs(board, r-1, c, set, current, b);
        }
        if(c+1<board[0].size() && board[r][c+1] == 'O' && !set.count((r)*board[0].size()+c+1)){
            set.insert((r)*board[0].size()+c+1);
            current.insert((r)*board[0].size()+c+1);
            if(c+1 ==board[0].size()-1){
                b = false;
            }
            dfs(board, r, c+1, set, current, b);
        }
         if(c-1>=0 && board[r][c-1] == 'O' && !set.count((r)*board[0].size()+c-1)){
            set.insert((r)*board[0].size()+c-1);
            current.insert((r)*board[0].size()+c-1);
            if(c-1 == 0){
                b = false;
            }
            dfs(board, r, c-1, set, current, b);
        }
    }
};