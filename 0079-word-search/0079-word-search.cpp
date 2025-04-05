class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> vec;
        fillVector(board, vec, word[0]);
        for(pair<int,int> start : vec){
            vector<pair<int,int>> visited = {start};
            if(canBeReached(start.first, start.second, board, word.substr(1), visited)){
                return true;
            }
        }
        return false;
    }

    bool canBeReached(int row, int col,vector<vector<char>>& board, string str, vector<pair<int,int>>& visited ){
        if(str.empty())return true;
        if(row+1<board.size() && board[row+1][col]==str[0] && find(visited.begin(),visited.end(), make_pair(row+1, col)) == visited.end()){
            visited.push_back({row+1,col});
            if(canBeReached(row+1, col, board, str.substr(1), visited )){
                return true;
            }
            visited.pop_back();
        }
        if(row-1>=0 && board[row-1][col]==str[0] && find(visited.begin(),visited.end(),make_pair(row-1, col)) == visited.end()){
            visited.push_back({row-1,col});
            if(canBeReached(row-1, col, board, str.substr(1), visited)){
                return true;
            }
            visited.pop_back();
        }
        if(col+1<board[0].size()  && board[row][col+1]==str[0] && find(visited.begin(),visited.end(), make_pair(row, col+1)) == visited.end()){
            visited.push_back({row,col+1});
            if(canBeReached(row, col+1, board, str.substr(1), visited)){
                return true;
            }
            visited.pop_back();
        }
        if(col-1>=0 && board[row][col-1]==str[0] && find(visited.begin(),visited.end(), make_pair(row, col-1)) == visited.end() ){
            visited.push_back({row,col-1});
             if(canBeReached(row, col-1, board, str.substr(1), visited)){
                return true;
            }
            visited.pop_back();
        }
        return false;
    }

    void fillVector(vector<vector<char>>& board,vector<pair<int,int>>& vec, char ch){
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(board[r][c]==ch){
                    vec.push_back({r,c});
                }
            }
        }
    }
};