class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int all =0;
        for(int n : apple)all+=n;
        sort(capacity.begin(),capacity.end());
        for(int i=capacity.size()-1; i>=0; i--){
            all-=capacity[i];
            if(all<=0){
                return capacity.size()-i;
            }
        }
        return -1;
    }
};