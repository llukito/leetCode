// leetcode number 733 (Flood Fill)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> bools(image.size(), vector<bool>(image[0].size(), false));
        check(image, sr, sc, color, image[sr][sc], bools);
        return image;
    }

    void check(vector<vector<int>>& image, int sr, int sc, int color, int start, vector<vector<bool>>& bools) {
        image[sr][sc] = color;
        if (sr + 1 < image.size() && image[sr + 1][sc] == start && !bools[sr + 1][sc]) {
            bools[sr + 1][sc] = true;
            check(image, sr + 1, sc, color, start, bools);
        }
        if (sr - 1 >= 0 && image[sr - 1][sc] == start && !bools[sr - 1][sc]) {
            bools[sr - 1][sc] = true;
            check(image, sr - 1, sc, color, start, bools);
        }
        if (sc + 1 < image[0].size() && image[sr][sc + 1] == start && !bools[sr][sc + 1]) {
            bools[sr][sc + 1] = true;
            check(image, sr, sc + 1, color, start, bools);
        }
        if (sc - 1 >= 0 && image[sr][sc - 1] == start && !bools[sr][sc - 1]) {
            bools[sr][sc - 1] = true;
            check(image, sr, sc - 1, color, start, bools);
        }
    }
};