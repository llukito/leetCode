class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> vect;
        int curr = 0;
        for(int n : nums){
            curr^=n;
        }
        for(int end = nums.size()-1; end>=0; end--){
            int k = 0;
            int temp = 0;
            bitset<32> b(curr);
            string s = b.to_string();
            string our;
            for(char ch : s){
                if(ch=='1'){
                    our+='0';
                } else {
                    our+='1';
                }
            }
            our = our.substr(our.size()-maximumBit);
            curr^=nums[end];
            vect.push_back(trans(our));
        }
        return vect;
    }

    int trans(string our){
        int res = 0;
        for(int i=0; i<our.length(); i++){
            if(our[i] == '1'){
                res+=1<<(our.length()-1-i);
            }
        }
        return res;
    }
};