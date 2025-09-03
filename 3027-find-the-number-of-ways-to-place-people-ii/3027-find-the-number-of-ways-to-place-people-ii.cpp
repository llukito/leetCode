class Solution {
public:
    long long numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2) return 0;

        vector<pair<int,int>> pts;
        pts.reserve(n);
        for (auto &p : points) pts.emplace_back(p[0], p[1]);
        sort(pts.begin(), pts.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        long long res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int yi = pts[i].second;
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int yj = pts[j].second;
                if (yj > yi) {
                    continue;  
                }
                if (maxY < yj) ++res;
                if (yj > maxY) maxY = yj;
            }
        }
        return res;
    }
};
