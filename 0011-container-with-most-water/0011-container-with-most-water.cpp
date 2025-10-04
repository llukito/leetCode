class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; int right = height.size()-1;
        int res = 0;
        while(left<height.size() && right>=0 && left<right){
            res = max(res, (right-left)*min(height[left], height[right]));
            if(height[left]<=height[right]){
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};