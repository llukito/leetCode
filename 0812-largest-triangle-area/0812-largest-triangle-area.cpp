class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for(int i=0; i<points.size()-2; i++){
            for(int j=i+1; j<points.size()-1; j++){
                for(int k=j+1; k<points.size(); k++){
                    res = max(res, space(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }

    double space(auto& i, auto& j, auto& k){
        double d = i[0]*j[1] + j[0]*k[1] + i[1]*k[0] - k[0]*j[1] - i[0]*k[1]-i[1]*j[0];
        return abs(d)/2.0;
    }
};