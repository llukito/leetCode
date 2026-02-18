class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        string str = b.to_string();
        str = str.substr((find(str.begin(), str.end(), '1')-str.begin()));
        for(int i = 0; i < str.size()-1; i++){
            if(str[i] == str[i+1])return false;
        }
        return true;
    }
};
