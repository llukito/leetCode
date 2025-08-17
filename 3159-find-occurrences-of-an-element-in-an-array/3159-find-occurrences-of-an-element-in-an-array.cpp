class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> vect(nums.size(), -1);
        int idx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==x){
                vect[idx++] = i;
            }
        }
        vector<int> res;
        for(int n : queries){
            n--;
            if(n>=vect.size()){
                res.push_back(-1);
            } else {
                res.push_back(vect[n]);
            }
        }
        return res;
    }
};