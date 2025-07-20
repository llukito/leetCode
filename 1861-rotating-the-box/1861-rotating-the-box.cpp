class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> res(boxGrid[0].size(), vector<char>(boxGrid.size(), '.'));
        for(int r=0; r<boxGrid.size(); r++){
            for(int c=0; c<boxGrid[0].size(); c++){
                res[c][boxGrid.size()-1-r] = boxGrid[r][c];
            }
        }
        for(int r=res.size()-1; r>=0; r--){
            for(int c=0; c<res[0].size(); c++){
                if(res[r][c] == '#'){
                    int row  = r+1;
                    while(row < res.size() && res[row][c] != '*' && res[row][c] != '#'){
                        row++;
                    }
                    res[r][c] = '.';
                    res[row-1][c] = '#';
                }
            }
        }
        return res;
    }
};