class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        if(k == 0)return nums;
        vector<int> nonNeg;
        for(int n : nums){
            if(n >= 0){
                nonNeg.push_back(n);
            }
        }
        int n = nonNeg.size();
        if(n == 0)return nums;
        vector<int> newPos(n, 0);
        k%=n;
        for(int i = 0; i < n; i++){
            newPos[(n+i-k)%n] = nonNeg[i];
        }
        vector<int> res;
        int idx = 0;
        for(int n : nums){
            if(n < 0){
                res.push_back(n);
            } else {
                res.push_back(newPos[idx++]);
            }
        }
        return res;
    }
};
