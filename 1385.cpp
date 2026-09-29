class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for(int n : arr1){
            bool valid = true;
            for(int m : arr2){
                if(abs(n-m)<=d){
                    valid = false;
                    break;
                }
            }
            if(valid)res++;
        }
        return res;
    }
};
