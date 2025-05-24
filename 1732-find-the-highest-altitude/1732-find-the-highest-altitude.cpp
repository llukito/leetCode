class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int curr = 0;
        for(int n : gain){
            curr+=n;
            mx = max(mx, curr);
        }
        return mx;
    }
};