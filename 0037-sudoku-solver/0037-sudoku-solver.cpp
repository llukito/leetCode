class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int todo = 0;
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(board[r][c] == '.')todo++;
            }
        }
        check(board, todo);
    }

    bool check(vector<vector<char>>& board,int todo){
        if(todo == 0){
            return true;
        }
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]=='.'){
                    for(char i='1'; i<='9'; i++){
                        board[r][c] = i;
                        if(valid(board, r, c, i)){
                            if(check(board, todo-1)){
                                return true;
                            }
                        }
                        board[r][c] = '.';
                    }
                    return false;
                }
            }
        }
        return false;
    }

    bool valid(vector<vector<char>>& board, int& row, int& col, char& ch) {
        for(int c=0; c<board[0].size(); c++){
            if(c == col)continue;
            if(board[row][c] == ch)return false;
        }
        for(int r=0; r<board.size(); r++){
            if(r == row)continue;
            if(board[r][col] == ch)return false;
        }
        int r = row/3;
        r*=3;
        int c = col/3;
        c*=3;
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(i == row && j == col)continue;
                if(board[i][j] == ch)return false;
            }
        }
        return true;
    }
};