class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                visit(isConnected, visited, i);
                count++;
            }
        }
        return count;
    }

    void visit(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[i][j] && !visited[j]){
                visited[j] = true;
                visit(isConnected, visited, j);
            }
        }
    }
};