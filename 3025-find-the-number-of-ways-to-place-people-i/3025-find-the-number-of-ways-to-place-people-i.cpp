class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if ((y1 >= y2 && x1 <= x2) || (y2 >= y1 && x2 <= x1)) {
                    int startX = min(x1, x2);
                    int startY = min(y1, y2);
                    int endX = max(x1, x2);
                    int endY = max(y1, y2);
                    bool b = true;
                    for (int k = 0; k < points.size(); k++) {
                        if ((points[k][0] == x1 && points[k][1] == y1) ||
                            (points[k][0] == x2 && points[k][1] == y2)) {
                            continue;
                        }
                        if (points[k][0] >= startX && points[k][0] <= endX &&
                            points[k][1] >= startY && points[k][1] <= endY) {
                            b = false;
                            break;
                        }
                    }
                    if (b)
                        res++;
                }
            }
        }
        return res;
    }
};