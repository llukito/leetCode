class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vect;
        for(vector<int> v : points){
            vect.push_back(v[0]);
        }  
        sort(vect.begin(), vect.end());
        int res = 0;
        for(int i=0; i<vect.size()-1; i++){
            res = max(res, vect[i+1]-vect[i]);
        } 
        return res;
    }
};