class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int numWalls = 0;
        for(auto& entry : walls){
            matrix[entry[0]][entry[1]] = 2;
            numWalls++;
        }
        for(auto& entry : guards){
            matrix[entry[0]][entry[1]] = 3;
        }
        int numOfVisited = 0;
        int numOfGuards = 0;
        for(auto& entry : guards){
            checkAll(matrix, visited, entry[0], entry[1], numOfVisited);
            cout<<" "<< numOfVisited<<endl;
            numOfGuards++;
        }
        return m*n - numOfVisited - numOfGuards - numWalls;
    }

    void checkAll(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int row, int col,int& numOfVisited){
        //down
        for(int r = row+1; r<matrix.size(); r++){
            if(matrix[r][col]!= 2){
                if(!visited[r][col] && matrix[r][col]!=3){
                    visited[r][col] = true;
                    numOfVisited++;
                }
            } else {
                break;
            }
        }
        //up
        for(int r = row-1; r>=0; r--){
            if(matrix[r][col]!= 2){
                if(!visited[r][col] && matrix[r][col]!=3){
                    visited[r][col] = true;
                    numOfVisited++;
                }
            } else {
                break;
            }
        }
        //right
        for(int c = col+1; c<matrix[0].size(); c++){
            if(matrix[row][c]!= 2){
                if(!visited[row][c] && matrix[row][c]!=3){
                    visited[row][c] = true;
                    numOfVisited++;
                }
            } else {
                break;
            }
        }
        //left
        for(int c = col-1; c>=0; c--){
            if(matrix[row][c]!= 2){
                if(!visited[row][c] && matrix[row][c]!=3){
                    visited[row][c] = true;
                    numOfVisited++;
                }
            } else {
                break;
            }
        }
    }
};