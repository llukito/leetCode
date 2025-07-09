class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cost = 0;
        int sx = points[0][0]; int sy = points[0][1];
        for(int i=1; i<points.size(); i++){
            int cx = points[i][0]; int cy = points[i][1];
            int diffx = abs(sx-cx); int diffy = abs(sy-cy);
            int dia = min(diffx, diffy);
            cost+=dia;
            cost+=max(diffx, diffy)-dia;
            sx = cx; sy = cy;
        }
        return cost;
    }
};