class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int num = 0;
            int x = queries[i][0]; int y = queries[i][1]; int r = queries[i][2];
            for(vector<int> vect : points){
                if(sqrt((vect[0]-x)*(vect[0]-x) + (vect[1]-y)*(vect[1]-y)) <= r)num++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};