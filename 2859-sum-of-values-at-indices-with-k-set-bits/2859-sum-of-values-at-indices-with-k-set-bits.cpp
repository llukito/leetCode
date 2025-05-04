class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(get(i)==k)sum+=nums[i];
        }
        return sum;
    }

    int get(int num){
        int all = 0;
        while(num!=0){
            if(num%2==1){
                all++;
            }
            num/=2;
        }
        return all;
    }
};