class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        unordered_set<int> visited;
        for(int r = 0; r<grid.size(); r++){
            for(int c = 0; c<grid[0].size(); c++){
                int idx = r*grid[0].size()+c;
                if(!visited.count(idx)){
                    cout<<r<<" "<<c<<endl;
                    bool b = false;
                    fill(grid, visited, b, r, c, grid[r][c], {-1,-1});
                    if(b)return true;
                }
            }
        }
        return false;
    }

    void fill(vector<vector<char>>& grid, unordered_set<int>& visited, bool& b, int row, int col, char ch, pair<int,int> parent){  
        int idx = row*grid[0].size() + col;
        if(visited.count(idx)){
            b = true;
        }
        visited.insert(idx);
        if(b)return;
        if(row+1<grid.size() && grid[row+1][col] == ch && !(row+1 == parent.first && col == parent.second)){
            fill(grid, visited, b, row+1, col, ch, {row, col});
        }
        if(row-1>=0 && grid[row-1][col] == ch && !(row-1 == parent.first && col == parent.second)){
            fill(grid, visited, b, row-1, col, ch, {row, col});
        }
        if(col+1<grid[0].size() && grid[row][col+1] == ch && !(row== parent.first && col+1 == parent.second)){
            fill(grid, visited, b, row, col+1, ch, {row, col});
        }
        if(col-1>=0 && grid[row][col-1] == ch && !(row== parent.first && col -1 == parent.second)){
            fill(grid, visited, b, row, col-1, ch, {row, col});
        }
    }
};