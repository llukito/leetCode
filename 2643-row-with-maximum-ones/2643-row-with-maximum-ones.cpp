class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max = 0;
        int ind = 0;
        for(int i=0; i<mat.size(); i++){
            vector<int> vec = mat[i];
            int ones = 0;
            for(int n : vec){
                if(n==1){
                    ones++;
                }
            }
            if(ones>max){
                max = ones;
                ind = i;
            }
        }
        return {ind,max};
    }
};