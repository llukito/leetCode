class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int res = 0;
        string str;
        vector<int> bools(digits.size(), false);
        unordered_set<string> set;
        fill(res, str, digits, bools, set);
        return res;
    }

    void fill(int& res, string& str, vector<int>& digits, vector<int>& bools, unordered_set<string>& set){
        if(str.size()==3){
            if(!set.count(str)){
                set.insert(str);
                if((str.back()-'0')%2==0){
                    res++;
                }
            }
            return;
        }
        for(int i = 0; i<digits.size(); i++){
            if(str.empty() && digits[i]==0)continue;
            if(bools[i])continue;

            str+=to_string(digits[i]);
            bools[i] = true;

            fill(res, str, digits, bools, set);

            bools[i] = false;
            str.pop_back();
        }
    }
};