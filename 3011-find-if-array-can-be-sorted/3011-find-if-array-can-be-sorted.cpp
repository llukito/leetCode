class Solution {
public:
    bool canSortArray(vector<int>& nums) {
       vector<string> bits;
       for(int n : nums){
            bits.push_back(transform(n));
       }
       if(valid(nums))return true;
       while(true){
            bool b = true;
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i+1]<nums[i]){
                    if(bits[i+1]==bits[i]){
                        b = false;
                        swap(nums[i],nums[i+1]);
                        swap(bits[i],bits[i+1]);
                    }
                }
            }
            if(b)return false;
            if(valid(nums))return true;
       }
    }

    bool valid(vector<int>& nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]<nums[i])return false;
        }
        return true;
    }

    string transform(int n){
        string str;
        while(n!=0){
            if(n%2==1){
                str+='1';
            }
            n/=2;
        }
        if(str.empty())return "0";
        return str;
    }
};