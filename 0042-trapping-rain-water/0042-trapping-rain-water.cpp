class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        maxLeft[0] = height[0];
        int n = height.size();
        for(int i = 1; i < n; i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }
        maxRight[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], height[i]);
        }
        int res = 0;
        for(int i=0; i<height.size(); i++){
            int r = min(maxLeft[i], maxRight[i])-height[i];
            if(r>0){
                res+=r;
            }
        }
        return res;
    }
};