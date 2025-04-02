class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1)return to_string(nums[0]);
        if(nums.size()==2){
            string str = to_string(nums[0]);
            str+="/";
            str+=to_string(nums[1]);
            return str;
        }
        string s = to_string(nums[0]);
        s+="/";
        s+="(";
        for(int i =1 ; i<nums.size();i++){
            s+=to_string(nums[i]);
            s+="/";
        }
        s = s.substr(0,s.length()-1);
        s+=")";
        return s;
    }
};