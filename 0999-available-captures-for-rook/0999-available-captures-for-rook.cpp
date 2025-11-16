class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == 'R'){
                    int res = 0;
                    for(int r = i+1; r < board.size(); r++){
                        if(board[r][j] == 'p'){
                            res++;
                            break;
                        } else if(board[r][j] == 'B'){
                            break;
                        }
                    }

                    for(int r = i-1; r>=0; r--){
                        if(board[r][j] == 'p'){
                            res++;
                            break;
                        } else if(board[r][j] == 'B'){
                            break;
                        }
                    }

                    for(int c = j+1; c<board.size(); c++){
                        if(board[i][c] == 'p'){
                            res++;
                            break;
                        } else if(board[i][c] == 'B'){
                            break;
                        }
                    }


                    for(int c = j-1; c>=0; c--){
                        if(board[i][c] == 'p'){
                            res++;
                            break;
                        } else if(board[i][c] == 'B'){
                            break;
                        }
                    }
                    return res;
                }
            }
        }
        return -1;
    }
};