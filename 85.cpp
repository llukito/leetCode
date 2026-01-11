class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            stack<int> s;
            for (int j = 0; j <= cols; j++) {
                int h = (j == cols) ? 0 : heights[j];
                while (!s.empty() && heights[s.top()] >= h) {
                    int curHeight = heights[s.top()];
                    s.pop();
                    int width = s.empty() ? j : j - s.top() - 1;
                    maxArea = max(maxArea, curHeight * width);
                }
                s.push(j);
            }
        }

        return maxArea;
    }
};
