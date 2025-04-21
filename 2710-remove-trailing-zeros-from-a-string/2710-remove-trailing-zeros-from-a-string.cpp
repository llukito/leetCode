class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.back()=='0'){
            num = num.substr(0,num.size()-1);
        }
        return num;
    }
};