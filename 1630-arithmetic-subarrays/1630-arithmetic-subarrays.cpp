class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> bools;
        for(int i=0; i<l.size(); i++){
            vector<int> vect(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(vect.begin(), vect.end());
            if(vect.size()<=1){
                bools.push_back(true);
            } else {
                int diff = vect[1]-vect[0];
                bool b = true;
                for(int i=2; i<vect.size(); i++){
                    if(vect[i]-vect[i-1] != diff){
                        b = false;
                        break;
                    }
                }
                bools.push_back(b);
            }
        }
        return bools;
    }
};