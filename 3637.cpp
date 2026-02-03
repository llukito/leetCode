class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0] >= nums[1])return false;

        bool b1 = false, b2 = true;
        int inc = 0, dec = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1])return false;

            if(nums[i] < nums[i+1]){
                if(b2)inc++;

                b2 = false;
                b1 = true;
            } else {
                if(b1)dec++;

                b1 = false;
                b2 = true;

            }
        }
        return inc == 2 && dec == 1;
    }
};
