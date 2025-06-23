class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<vector<int>> rows(grid.size(), vector<int>(grid.size(), 0));
        unordered_set<int> set;
        vector<int> vect(grid.size(), 0);
        vector<int> vect2(grid.size(), 0);
        for(int r=0; r<grid.size(); r++){
            int el = -1;
            int row = 0;
            int col = 0;
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c]>el){
                    el = grid[r][c];
                    row = r;
                    col = c;
                }
            }
            vect[r] = el;
            set.insert(row*grid[0].size()+col);
        }
        for(int c=0; c<grid[0].size(); c++){
            int el = -1;
            int row = 0;
            int col = 0;
            for(int r=0; r<grid.size(); r++){
                if(grid[r][c]>el){
                    el = grid[r][c];
                    row = r;
                    col = c;
                }
            }
            vect2[c] = el;
            set.insert(row*grid[0].size()+col);
        }
        int res = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(!set.count(r*grid[0].size()+c)){
                    res+=min(vect[r], vect2[c])-grid[r][c];
                }
            }
        }
        return res;
    }
};