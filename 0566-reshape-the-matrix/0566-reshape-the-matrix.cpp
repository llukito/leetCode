class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> vec;
        for(vector<int> v : mat){
            for(int n : v){
                vec.push_back(n);
            }
        }
        int index = 0;
        if(r*c != mat.size()*mat[0].size())return mat;
        cout<<"here";
        vector<vector<int>> grid(r, vector<int>(c,-1));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                grid[i][j]=vec[index++];
            }
        }
        return grid;
    }
};