class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos; vector<int> neg;
        for(int n : nums){
            if(n>0){
                pos.push_back(n);
            } else {
                neg.push_back(n);
            }
        }
        vector<int> res;
        for(int i=0; i<pos.size(); i++){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};