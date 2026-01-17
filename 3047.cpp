class Solution {
public:
    #define MAX(a, b) ((a)>(b)) ? (a) : (b)
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                // first rect
                int x11 = bottomLeft[i][0]; int y11 = bottomLeft[i][1];
                int x12 = topRight[i][0]; int y12 = topRight[i][1];
                // second rect
                int x21 = bottomLeft[j][0]; int y21 = bottomLeft[j][1];
                int x22 = topRight[j][0]; int y22 = topRight[j][1];

                if(x11 >= x22 || x21 >= x12)continue; // x coordinates
                if(y11 >= y22 || y21 >= y12)continue; // y coordinates

                // if here, then they intersect
                // bottom left
                int x31 = max(x11, x21); int y31 = max(y11, y21);
                // top right
                int x32 = min(x12, x22); int y32 = min(y12, y22);
                int side = min(abs(x31-x32), abs(y31-y32));
                res = MAX(res, 1ll*side*side);
            }
        }
        return res;
    }
};
