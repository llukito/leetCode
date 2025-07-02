class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        vector<int> v{rStart, cStart};
        res.push_back(v);
        int total = rows*cols-1;
        int left = 2; int down = 1; int Sright = 1; int up = 2; int Bright = 1;
        int r = rStart; int c = cStart;
        while(total>0){
            cout<<total<<endl;
            for(int i=0; i<Sright; i++){
                c++;
                if(r<rows && c<cols && r>=0 && c>=0){
                    vector<int> vect{r, c};
                    res.push_back(vect);
                    total--;
                }
            }
            Sright++;
            if(total <= 0)break;
            for(int i=0; i<down; i++){
                r++;
                if(r<rows && c<cols && r>=0 && c>=0){
                    vector<int> vect{r, c};
                    res.push_back(vect);
                    total--;
                }
            }
            down+=2;
            if(total <= 0)break;
            for(int i=0; i<left; i++){
                c--;
                if(r<rows && c<cols && r>=0 && c>=0){
                    vector<int> vect{r, c};
                    res.push_back(vect);
                    total--;
                }
            }
            left+=2;
            if(total <= 0)break;
            for(int i=0; i<up; i++){
                r--;
                if(r<rows && c<cols && r>=0 && c>=0){
                    vector<int> vect{r, c};
                    res.push_back(vect);
                    total--;
                }
            }
            up+=2;
            if(total <= 0)break;
            for(int i=0; i<Bright; i++){
                c++;
                if(r<rows && c<cols && r>=0 && c>=0){
                    vector<int> vect{r, c};
                    res.push_back(vect);
                    total--;
                }
            }
            Bright+=1;
        }
        return res;
    }
};