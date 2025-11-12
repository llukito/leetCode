class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = allOnes(nums);
        int min_size = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                int gcd = getGcd(nums, i, j);
                if(gcd == 1){
                    min_size = min(min_size, j-i+1);
                }
            }
        }
        if(min_size == 1)return min_size == INT_MAX ? -1 : min_size - 1 + nums.size() - n;
        return min_size == INT_MAX ? -1 : min_size - 1 + nums.size() - 1 - n;
    }

    int allOnes(vector<int>& nums){
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)n++;
        }
        return n;
    }

    int getGcd(vector<int>& nums, int i, int j){
        if(i == j)return nums[i];
        int num = nums[i];
        for(int h = i + 1; h <= j; h++){
            num = gcd(num, nums[h]);
        }   
        return num;
    }

    int gcd(int a, int b){
        while (b != 0) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};
